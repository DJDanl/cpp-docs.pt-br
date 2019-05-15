---
title: 'TN058: Implementação do estado do módulo MFC'
ms.date: 06/28/2018
helpviewer_keywords:
- thread state [MFC]
- module states [MFC], managing state data
- TN058
- MFC, managing state data
- module states [MFC], switching
- DLLs [MFC], module states
- process state [MFC]
ms.assetid: 72f5b36f-b3da-4009-a144-24258dcd2b2f
ms.openlocfilehash: d803dba36b7790173b21dacb6cb34241f27dfb96
ms.sourcegitcommit: 934cb53fa4cb59fea611bfeb9db110d8d6f7d165
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/14/2019
ms.locfileid: "65610963"
---
# <a name="tn058-mfc-module-state-implementation"></a>TN058: Implementação do estado do módulo MFC

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

Essa observação técnica descreve a implementação de construções de "Estado do módulo MFC". Uma compreensão da implementação do estado do módulo é fundamental para usar o MFC compartilhadas DLLs de uma DLL (ou no servidor OLE em processo).

Antes de ler esta nota, consulte "Gerenciando o dados do estado dos módulos de MFC" na [criando novos documentos, Windows e modos de exibição](../mfc/creating-new-documents-windows-and-views.md). Este artigo contém informações de uso importantes e informações de visão geral sobre esse assunto.

## <a name="overview"></a>Visão geral

Há três tipos de informações de estado do MFC: Estado do módulo, estado do processo e o estado de Thread. Às vezes, esses tipos de estado podem ser combinados. Por exemplo, mapas de identificador do MFC são módulo local e o local de thread. Isso permite que os dois módulos diferentes ter mapas diferentes em cada um dos seus threads.

Estado do processo e o estado de Thread são semelhantes. Esses itens de dados são coisas que têm sido, tradicionalmente, as variáveis globais, mas têm precisam ser específicos para um determinado processo ou thread para Win32s adequado de suporte ou para suporte de multithreading apropriado. Qual categoria um determinado item de dados se encaixa no depende desse item e a semântica desejada em relação a limites de processo e thread.

Estado do módulo é o único que pode conter estado realmente global ou estado de processo local ou local de thread. Além disso, ele pode ser alternado rapidamente.

## <a name="module-state-switching"></a>Alternância de estado do módulo

Cada thread contém um ponteiro para o estado do módulo "atual" ou "ativos" (não é surpreendente, o ponteiro é parte do estado de local de thread do MFC). Esse ponteiro é alterado quando o thread de execução passa um limite de módulo, como um aplicativo de chamada em um controle OLE ou DLL ou um controle OLE retornar a chamada para um aplicativo.

O estado atual do módulo é alternado chamando `AfxSetModuleState`. Geralmente, você nunca será lidar diretamente com a API. MFC, em muitos casos, irá chamá-lo para você (em WinMain, pontos de entrada do OLE, `AfxWndProc`, etc.). Isso é feito em qualquer componente que você escrever por meio da vinculação estática em um especial `WndProc`e um especial `WinMain` (ou `DllMain`) que sabe qual estado do módulo deve estar atualizado. Você pode ver esse código, observando DLLMODUL. CPP ou APPMODUL. CPP no diretório MFC\SRC.

É raro que você deseja definir o estado do módulo e, em seguida, não defini-la novamente. Na maioria das vezes que você deseja "push" de seu próprio módulo de estado que o atual e em seguida, depois de terminar, "pop" volta o contexto original. Isso é feito pela macro [AFX_MANAGE_STATE](reference/extension-dll-macros.md#afx_manage_state) e a classe especial `AFX_MAINTAIN_STATE`.

`CCmdTarget` tem recursos especiais para dar suporte a alternância de estado do módulo. Em particular, uma `CCmdTarget` é a classe raiz usado para a automação OLE e OLE COM pontos de entrada. Qualquer outro ponto de entrada, como exposto ao sistema, esses pontos de entrada devem definir o estado do módulo correto. Como faz um determinado `CCmdTarget` souber qual o estado do módulo "correto" deve ser a resposta é que ele "memoriza" qual é o estado do módulo "atual" quando ele é construído, que, de modo que ele possa definir o estado atual do módulo para que "lembrada" chamado valor quando ela é posterior. Como resultado, o módulo de estado que uma determinada `CCmdTarget` objeto está associado com é o estado do módulo que era atual quando o objeto for construído. Veja um exemplo simple de carregamento de um servidor INPROC, criação de um objeto e chamando seus métodos.

1. A DLL é carregada pelo OLE usando `LoadLibrary`.

2. `RawDllMain` é chamado pela primeira vez. Ele define o estado do módulo para o estado de módulo estático conhecido para a DLL. Por esse motivo `RawDllMain` está vinculado estaticamente para a DLL.

1. O construtor para a fábrica de classe associado ao nosso objeto é chamado. `COleObjectFactory` é derivado de `CCmdTarget` e como resultado, ele se lembra em qual estado do módulo que ele tiver sido instanciado. Isso é importante — quando a fábrica de classes é solicitada a criar objetos, ele agora sabe que estado de módulo para tornar atual.

4. `DllGetClassObject` é chamado para obter a fábrica de classes. Pesquisa a lista de fábrica de classe associada a esse módulo MFC e o retorna.

5. `COleObjectFactory::XClassFactory2::CreateInstance` é chamado. Antes de criar o objeto e retorná-lo, essa função define o estado do módulo para o estado do módulo que era atual na etapa 3 (aquele que era atual quando o `COleObjectFactory` foi instanciado). Isso é feito dentro de [METHOD_PROLOGUE](com-interface-entry-points.md).

1. Quando o objeto é criado, ele também é um `CCmdTarget` derivados e da mesma forma `COleObjectFactory` lembradas qual estado do módulo estava ativo, assim como o novo objeto. Agora que o objeto sabe qual estado de módulo para alternar para sempre que ele é chamado.

1. O cliente chama uma função no objeto OLE COM ela recebida de seu `CoCreateInstance` chamar. Quando o objeto é chamado, ele usa `METHOD_PROLOGUE` para alternar o estado do módulo exatamente como `COleObjectFactory` faz.

Como você pode ver, o estado do módulo é propagado do objeto ao objeto, conforme eles são criados. É importante ter o estado de módulo definido adequadamente. Se não for definido, seu objeto DLL ou COM pode interagir mal com um aplicativo do MFC que está chamando, ou talvez não consiga localizar seus próprios recursos ou pode falhar em outras maneiras de lamentável.

Observe que certos tipos de DLLs, especificamente as DLLs de "extensão do MFC" não alternam o estado do módulo em seu `RawDllMain` (na verdade, eles geralmente não ainda tiverem um `RawDllMain`). Isso é porque elas devem se comportar "como se" eles fossem realmente presentes no aplicativo que os utiliza. Eles são uma grande parte do aplicativo que está em execução e é sua intenção de modificar o estado global do aplicativo.

Controles OLE e outras DLLs são muito diferentes. Eles não querem modificar o estado do aplicativo de chamada; o aplicativo que está chamando-los pode não ser de até mesmo um aplicativo do MFC e não pode haver nenhum estado para modificar. Essa é a razão de alternância de estado do módulo era inventado.

Para funções exportadas de uma DLL, por exemplo, um que inicia uma caixa de diálogo na DLL, você precisará adicionar o código a seguir para o início da função:

```cpp
AFX_MANAGE_STATE(AfxGetStaticModuleState())
```

Isso alterna o estado atual do módulo com o estado retornado de [AfxGetStaticModuleState](reference/extension-dll-macros.md#afxgetstaticmodulestate) até o final do escopo atual.

Problemas com os recursos em DLLs ocorrerá se a macro AFX_MODULE_STATE não for usada. Por padrão, o MFC usa o identificador de recurso do aplicativo principal para carregar o modelo de recurso. Esse modelo, na verdade, é armazenado na DLL. A causa raiz é que as informações de estado do módulo do MFC não tem sido alternadas pela macro AFX_MODULE_STATE. O identificador de recurso é recuperado do estado do módulo do MFC. Não alternar o estado do módulo faz com que o identificador de recurso incorreto a ser usado.

AFX_MODULE_STATE não precisa ser colocado em cada função na DLL. Por exemplo, `InitInstance` pode ser chamado pelo código do MFC no aplicativo sem AFX_MODULE_STATE porque MFC mudará automaticamente o estado do módulo antes `InitInstance` e, em seguida, alterna-lo de volta depois `InitInstance` retorna. O mesmo é verdadeiro para todos os manipuladores de mapa de mensagem. DLLs MFC regulares, na verdade, tem um procedimento de janela mestre especial que alterna automaticamente o estado do módulo antes de encaminhar qualquer mensagem.

## <a name="process-local-data"></a>Processar dados de Local

Processar dados de local não seria de tal grande preocupação se não fosse para a dificuldade do modelo DLL Win32s. No Win32s todas as DLLs de compartilham seus dados globais, mesmo quando carregados por vários aplicativos. Isso é muito diferente do modelo de dados DLL Win32 "real", onde cada DLL obtém uma cópia separada do seu espaço de dados em cada processo que anexa à DLL. Para adicionar a complexidade, dados alocados no heap em uma DLL Win32s são na verdade processo específico (pelo menos até onde vai de propriedade). Considere a dados e o código a seguir:

```cpp
static CString strGlobal; // at file scope

__declspec(dllexport)
void SetGlobalString(LPCTSTR lpsz)
{
    strGlobal = lpsz;
}

__declspec(dllexport)
void GetGlobalString(LPCTSTR lpsz, size_t cb)
{
    StringCbCopy(lpsz, cb, strGlobal);
}
```

Considere o que acontece se o código acima em estará em uma DLL e que a DLL é carregada por dois processos A e B (poderia, na verdade, ser duas instâncias do mesmo aplicativo). Um chamadas `SetGlobalString("Hello from A")`. Como resultado, a memória é alocada para o `CString` dados no contexto do processo de r. tenha em mente que o `CString` em si é global e é visível para A e b. Agora chama B `GetGlobalString(sz, sizeof(sz))`. B será capaz de ver os dados de um conjunto. Isso ocorre porque o Win32s não oferece nenhuma proteção entre processos, como Win32 faz. Esse é o primeiro problema; em muitos casos não é desejável ter um aplicativo de afetar os dados globais que são considerados para pertencer a um aplicativo diferente.

Há também problemas adicionais. Digamos que A agora é encerrado. Quando um for encerrado, a memória usada pelo '`strGlobal`' cadeia de caracteres é disponibilizada para o sistema — ou seja, toda a memória alocada por um processo é liberada automaticamente pelo sistema operacional. Ele não é liberado porque o `CString` destruidor está sendo chamado; ele não tiver sido chamado. Ele é liberado de simplesmente porque o aplicativo que alocou, deixou a cena. Agora, se chamado B `GetGlobalString(sz, sizeof(sz))`, ele não pode obter dados válidos. Algum outro aplicativo pode ter usado o que a memória para outra coisa.

Claramente há um problema. MFC 3.x usado uma técnica chamada armazenamento local de thread (TLS). MFC 3.x alocará um índice TLS que atua como um índice de armazenamento local de processo, de fato em Win32s, embora não seja chamado que e, em seguida, fará referência a todos os dados com base em que o índice TLS. Isso é semelhante ao índice TLS que foi usado para armazenar dados de local de thread no Win32 (consulte abaixo para obter mais informações sobre esse assunto). Isso causou cada DLL do MFC utilizar a pelo menos dois índices TLS por processo. Quando você levar em conta ao carregar muitos controle DLLs OLE (OCXs), você rapidamente ficar sem índices TLS (são apenas 64 disponível). Além disso, tinha MFC colocar todos os dados em um só lugar, em uma única estrutura. Ele não era muito extensível e não era ideal em relação ao seu uso de índices TLS.

MFC 4.x soluciona isso com um conjunto de modelos de classe, você pode "circunde" os dados que devem ser um processo local. Por exemplo, o problema mencionado acima pode ser reparado pelo escrever:

```cpp
struct CMyGlobalData : public CNoTrackObject
{
    CString strGlobal;
};
CProcessLocal<CMyGlobalData> globalData;

__declspec(dllexport)
void SetGlobalString(LPCTSTR lpsz)
{
    globalData->strGlobal = lpsz;
}

__declspec(dllexport)
void GetGlobalString(LPCTSTR lpsz, size_t cb)
{
    StringCbCopy(lpsz, cb, globalData->strGlobal);
}
```

MFC implementa isso em duas etapas. Em primeiro lugar, há uma camada na parte superior do Win32 __Tls\*__  APIs (**TlsAlloc**, **TlsSetValue**, **TlsGetValue**, etc.) que usar apenas dois índices TLS por processo, não importa quantas DLLs que você tem. Segundo, o `CProcessLocal` modelo é fornecido para acessar esses dados. Ele substitui o operador -> que é o que permite que a sintaxe intuitiva, você pode ver acima. Todos os objetos que são encapsulados pelo `CProcessLocal` deve ser derivado de `CNoTrackObject`. `CNoTrackObject` Fornece um alocador de nível inferior (**LocalAlloc**/**LocalFree**) e um destruidor virtual, de modo que o MFC automaticamente pode destruir os objetos de processo local quando o processo é encerrado. Esses objetos podem ter um destruidor personalizado se a limpeza adicional é necessária. O exemplo acima não exige um, uma vez que o compilador irá gerar um destruidor padrão para destruir o embedded `CString` objeto.

Há outras vantagens dessa abordagem interessantes. Não só são todos `CProcessLocal` objetos destruídos automaticamente, eles não são criados até que sejam necessários. `CProcessLocal::operator->` instanciará o objeto associado na primeira vez que ele é chamado e não antes. No exemplo acima, isso significa que o '`strGlobal`' cadeia de caracteres não será construída até a primeira vez `SetGlobalString` ou `GetGlobalString` é chamado. Em alguns casos, isso pode ajudar a diminuir o tempo de inicialização da DLL.

## <a name="thread-local-data"></a>Dados de Local de thread

Semelhante ao processar os dados locais, dados de local de thread são usados quando os dados devem ser locais para um determinado thread. Ou seja, você precisa de uma instância separada dos dados para cada thread que acessa esses dados. Isso pode muitas vezes ser usado no lugar de mecanismos de sincronização abrangente. Se os dados não precisam ser compartilhado por vários threads, esses mecanismos podem ser caras e desnecessários. Suponha que tínhamos uma `CString` objeto (muito parecido com o exemplo acima). Fazemos isso de thread local, encapsulando-o com um `CThreadLocal` modelo:

```cpp
struct CMyThreadData : public CNoTrackObject
{
    CString strThread;
};
CThreadLocal<CMyThreadData> threadData;

void MakeRandomString()
{
    // a kind of card shuffle (not a great one)
    CString& str = threadData->strThread;
    str.Empty();
    while (str.GetLength() != 52)
    {
        unsigned int randomNumber;
        errno_t randErr;
        randErr = rand_s(&randomNumber);

        if (randErr == 0)
        {
            TCHAR ch = randomNumber % 52 + 1;
            if (str.Find(ch) <0)
            str += ch; // not found, add it
        }
    }
}
```

Se `MakeRandomString` foi chamado de dois threads diferentes, cada um seria "embaralhar" a cadeia de caracteres de maneiras diferentes sem interferir com as outras. Isso ocorre porque há realmente um `strThread` instância por thread, em vez de uma única instância global.

Observe como uma referência é usada para capturar o `CString` abordar uma vez, em vez de uma vez por iteração do loop. O código de loop poderia ter sido escrito com `threadData->strThread` everywhere '`str`' for usado, mas o código seria muito mais lento em execução. É melhor armazenar em cache uma referência aos dados quando essas referências ocorrerem em loops.

O `CThreadLocal` modelo de classe usa os mesmos mecanismos que `CProcessLocal` não e as mesmas técnicas de implementação.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
