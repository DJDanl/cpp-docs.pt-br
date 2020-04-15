---
title: 'TN058: implementação de estado do módulo MFC'
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
ms.openlocfilehash: b64fb6b97474007c44a2124315e83e1ac119f9ec
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366615"
---
# <a name="tn058-mfc-module-state-implementation"></a>TN058: implementação de estado do módulo MFC

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para as últimas informações, recomenda-se que você pesquise o tópico de interesse no índice de documentação on-line.

Esta nota técnica descreve a implementação de construções de "estado de módulo" do MFC. Uma compreensão da implementação do estado do módulo é fundamental para o uso das DLLs compartilhadas do MFC a partir de um DLL (ou servidor em processo OLE).

Antes de ler esta nota, consulte "Gerenciando os Dados do Estado dos Módulos MFC" na [Criação de Novos Documentos, Windows e Visualizações](../mfc/creating-new-documents-windows-and-views.md). Este artigo contém informações importantes de uso e informações de visão geral sobre este assunto.

## <a name="overview"></a>Visão geral

Existem três tipos de informações de estado de MFC: Estado do Módulo, Estado do Processo e Estado da Linha. Às vezes, esses tipos de estado podem ser combinados. Por exemplo, os mapas de punho do MFC são locais do módulo e do segmento local. Isso permite que dois módulos diferentes tenham mapas diferentes em cada um de seus segmentos.

Estado de processo e Estado de Segmento são semelhantes. Esses itens de dados são coisas que tradicionalmente são variáveis globais, mas precisam ser específicos para um determinado processo ou segmento para suporte adequado do Win32s ou para suporte de multithreading adequado. Qual categoria um determinado item de dados se encaixa depende desse item e de sua semântica desejada no que diz respeito aos limites de processo e segmento.

O Estado do Módulo é único na forma de conter um estado ou estado verdadeiramente global que é local ou local de processo. Além disso, pode ser trocado rapidamente.

## <a name="module-state-switching"></a>Comutação do estado do módulo

Cada segmento contém um ponteiro para o estado do módulo "atual" ou "ativo" (não surpreendentemente, o ponteiro faz parte do estado local do segmento mfc). Este ponteiro é alterado quando o segmento de execução passa um limite de módulo, como um aplicativo chamando para um Controle OLE ou DLL, ou um Controle OLE chamando de volta para um aplicativo.

O estado atual do `AfxSetModuleState`módulo é comutado por chamada . Na maioria das vezes, você nunca vai lidar diretamente com a API. O MFC, em muitos casos, vai chamá-lo para você `AfxWndProc`(em WinMain, OLE entry-points, etc.). Isso é feito em qualquer componente que você `WndProc`escreva, `WinMain` vinculando estáticamente em um especial , e um especial (ou `DllMain`) que sabe qual estado do módulo deve ser atual. Você pode ver este código olhando para DLLMODUL. CPP ou APPMODUL. CPP no diretório MFC\SRC.

É raro que você queira definir o estado do módulo e, em seguida, não configurá-lo para trás. Na maioria das vezes você quer "empurrar" seu próprio estado de módulo como o atual e, em seguida, depois que você terminar, "pop" o contexto original de volta. Isso é feito pela [macro](reference/extension-dll-macros.md#afx_manage_state) AFX_MANAGE_STATE `AFX_MAINTAIN_STATE`e pela classe especial.

`CCmdTarget`tem recursos especiais para suportar a comutação do estado do módulo. Em particular, `CCmdTarget` a é a classe raiz usada para automação OLE e pontos de entrada OLE COM. Como qualquer outro ponto de entrada exposto ao sistema, esses pontos de entrada devem definir o estado correto do módulo. Como um `CCmdTarget` dado sabe qual deve ser o estado do módulo "correto" A resposta é que ele "lembra" o estado do módulo "atual" quando é construído, de tal forma que ele pode definir o estado atual do módulo para esse valor "lembrado" quando ele é chamado mais tarde. Como resultado, o módulo afirma `CCmdTarget` que um determinado objeto está associado é o estado do módulo que estava atual quando o objeto foi construído. Tome um exemplo simples de carregar um servidor INPROC, criar um objeto e chamar seus métodos.

1. O DLL é carregado pelo `LoadLibrary`OLE usando .

1. `RawDllMain`é chamado primeiro. Ele define o estado do módulo para o estado do módulo estático conhecido para o DLL. Por esta `RawDllMain` razão está estám estáticamente ligados à DLL.

1. O construtor da fábrica de classe associada ao nosso objeto é chamado. `COleObjectFactory`é derivado `CCmdTarget` e, como resultado, ele lembra em que módulo estado foi instanciado. Isso é importante — quando a fábrica de classe é solicitada a criar objetos, ela sabe agora qual estado de módulo tornar atual.

1. `DllGetClassObject`é chamado para obter a fábrica de classe. O MFC pesquisa a lista de fábrica de classes associada a este módulo e a devolve.

1. `COleObjectFactory::XClassFactory2::CreateInstance` é chamado. Antes de criar o objeto e devolvê-lo, esta função define o estado do módulo para `COleObjectFactory` o estado do módulo que estava atual na etapa 3 (aquela que estava atual quando o foi instanvada). Isso é feito dentro de [METHOD_PROLOGUE.](com-interface-entry-points.md)

1. Quando o objeto é criado, ele `CCmdTarget` também é um `COleObjectFactory` derivado e da mesma forma lembrado qual estado do módulo estava ativo, assim como este novo objeto. Agora, o objeto sabe para qual estado do módulo mudar quando for chamado.

1. O cliente chama uma função no objeto OLE COM que recebeu de sua `CoCreateInstance` chamada. Quando o objeto é `METHOD_PROLOGUE` chamado, ele usa `COleObjectFactory` para alternar o estado do módulo, assim como faz.

Como você pode ver, o estado do módulo é propagado de objeto para objeto à medida que são criados. É importante ter o estado do módulo definido adequadamente. Se não estiver definido, seu objeto DLL ou COM pode interagir mal com um aplicativo MFC que o está chamando, ou pode ser incapaz de encontrar seus próprios recursos, ou pode falhar de outras maneiras miseráveis.

Observe que certos tipos de DLLs, especificamente DLLs "MFC Extension" não alternam o estado do módulo em seu `RawDllMain` (na verdade, eles geralmente nem têm um `RawDllMain`). Isso porque eles têm a intenção de se comportar "como se" estivessem realmente presentes no aplicativo que os utiliza. Eles são muito parte do aplicativo que está sendo executado e é sua intenção modificar o estado global desse aplicativo.

Controles OLE e outros DLLs são muito diferentes. Eles não querem modificar o estado do aplicativo de chamada; o aplicativo que está chamando-os pode nem ser um aplicativo MFC e, portanto, pode não haver estado para modificar. Esta é a razão pela qual a troca de estado do módulo foi inventada.

Para funções exportadas de uma DLL, como aquela que lança uma caixa de diálogo em sua DLL, você precisa adicionar o seguinte código ao início da função:

```cpp
AFX_MANAGE_STATE(AfxGetStaticModuleState())
```

Isso troca o estado atual do módulo com o estado retornado de [AfxGetStaticModuleState](reference/extension-dll-macros.md#afxgetstaticmodulestate) até o final do escopo atual.

Problemas com recursos em DLLs ocorrerão se a macro AFX_MODULE_STATE não for utilizada. Por padrão, o MFC usa a alça de recurso do aplicativo principal para carregar o modelo de recurso. Este modelo é realmente armazenado na DLL. A causa principal é que as informações do estado do módulo do MFC não foram comutadas pela AFX_MODULE_STATE macro. A alça de recurso é recuperada do estado do módulo do MFC. Não alternar o estado do módulo faz com que a alça de recurso errada seja usada.

AFX_MODULE_STATE não precisa ser colocado em todas as funções na DLL. Por exemplo, `InitInstance` pode ser chamado pelo código MFC no aplicativo sem AFX_MODULE_STATE `InitInstance` porque o MFC `InitInstance` muda automaticamente o estado do módulo antes e, em seguida, o alterna de volta após o retorno. O mesmo vale para todos os manipuladores de mapas de mensagens. DLLs MFC regulares na verdade têm um procedimento especial de janela mestre que muda automaticamente o estado do módulo antes de roteamento de qualquer mensagem.

## <a name="process-local-data"></a>Processar dados locais

Processar dados locais não seria de grande preocupação se não fosse pela dificuldade do modelo Win32s DLL. No Win32s todos os DLLs compartilham seus dados globais, mesmo quando carregados por vários aplicativos. Isso é muito diferente do modelo de dados "real" Win32 DLL, onde cada DLL obtém uma cópia separada de seu espaço de dados em cada processo que se anexa ao DLL. Para aumentar a complexidade, os dados alocados no heap em um DLL Win32s são de fato específicos do processo (pelo menos no que diz respeito à propriedade). Considere os seguintes dados e códigos:

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

Considere o que acontece se o código acima estiver localizado em uma DLL e que a DLL seja carregada por dois processos A e B (poderia, de fato, ser duas instâncias da mesma aplicação). Uma `SetGlobalString("Hello from A")`chamada. Como resultado, a memória é `CString` alocada para os dados no contexto `CString` do processo A. Tenha em mente que o próprio é global e é visível tanto para A quanto para B. Agora B `GetGlobalString(sz, sizeof(sz))`chama. B será capaz de ver os dados que A definir. Isso porque o Win32s não oferece proteção entre processos como o Win32. Esse é o primeiro problema; em muitos casos, não é desejável que um aplicativo afete dados globais que são considerados de propriedade de um aplicativo diferente.

Há problemas adicionais também. Digamos que A sai agora. Quando A sai, a memória`strGlobal`usada pela string ' é disponibilizada para o sistema - ou seja, toda a memória alocada pelo processo A é liberada automaticamente pelo sistema operacional. Não é libertado `CString` porque o destruidor está sendo chamado; ainda não foi chamado. Ele é liberado simplesmente porque o aplicativo que o alocou saiu de cena. Agora, se `GetGlobalString(sz, sizeof(sz))`B chamado, ele pode não obter dados válidos. Algum outro aplicativo pode ter usado essa memória para outra coisa.

Claramente existe um problema. O MFC 3.x usou uma técnica chamada thread-local storage (TLS). O MFC 3.x alocaria um índice TLS que, sob o Win32s, realmente atua como um índice de armazenamento local de processo, embora não seja chamado assim e, em seguida, referenciaria todos os dados com base nesse índice TLS. Isso é semelhante ao índice TLS que foi usado para armazenar dados locais de thread no Win32 (veja abaixo para obter mais informações sobre esse assunto). Isso fez com que cada DLL MFC utilizasse pelo menos dois índices TLS por processo. Quando você contabiliza o carregamento de muitos DLLs (OCXs) do Controle OLE, você rapidamente se saqueia os índices TLS (há apenas 64 disponíveis). Além disso, a MFC teve que colocar todos esses dados em um só lugar, em uma única estrutura. Não era muito extensível e não era ideal no que diz respeito ao uso de índices TLS.

O MFC 4.x aborda isso com um conjunto de modelos de classe que você pode "envolver" em torno dos dados que devem ser processados localmente. Por exemplo, o problema mencionado acima poderia ser corrigido por escrito:

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

O MFC implementa isso em duas etapas. Primeiro, há uma camada no topo das APIs Win32 __Tls\* __ (**TlsAlloc,** **TlsSetValue,** **TlsGetValue,** etc.) que usam apenas dois índices TLS por processo, não importa quantos DLLs você tenha. Em segundo `CProcessLocal` lugar, o modelo é fornecido para acessar esses dados. Ele substitui o operador-> que é o que permite a sintaxe intuitiva que você vê acima. Todos os objetos `CProcessLocal` que são `CNoTrackObject`embrulhados devem ser derivados de . `CNoTrackObject`fornece um alocador de nível inferior **(LocalAlloc**/**LocalFree)** e um destruidor virtual de modo que o MFC possa destruir automaticamente os objetos locais do processo quando o processo for encerrado. Esses objetos podem ter um destruidor personalizado se for necessária uma limpeza adicional. O exemplo acima não requer um, uma vez que o compilador gerará `CString` um destructor padrão para destruir o objeto incorporado.

Há outras vantagens interessantes nessa abordagem. Não só `CProcessLocal` todos os objetos são destruídos automaticamente, eles não são construídos até que sejam necessários. `CProcessLocal::operator->`vai instanciar o objeto associado na primeira vez que ele é chamado, e não mais cedo. No exemplo acima, isso significa`strGlobal`que a string ' não `SetGlobalString` será `GetGlobalString` construída até a primeira vez ou é chamada. Em alguns casos, isso pode ajudar a diminuir o tempo de inicialização da DLL.

## <a name="thread-local-data"></a>Dados locais do segmento

Semelhante ao processo de dados locais, os dados locais do segmento são usados quando os dados devem ser locais para um determinado segmento. Ou seja, você precisa de uma instância separada dos dados para cada segmento que acessa esses dados. Isso pode muitas vezes ser usado em vez de extensos mecanismos de sincronização. Se os dados não precisarem ser compartilhados por vários threads, tais mecanismos podem ser caros e desnecessários. Suponha `CString` que tínhamos um objeto (muito parecido com a amostra acima). Podemos torná-lo local de rosca, envolvendo-o com um `CThreadLocal` modelo:

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

Se `MakeRandomString` fosse chamado de dois tópicos diferentes, cada um iria "embaralhar" a corda de maneiras diferentes sem interferir com o outro. Isso porque há, `strThread` na verdade, uma instância por thread em vez de apenas uma instância global.

Observe como uma referência é `CString` usada para capturar o endereço uma vez em vez de uma vez por iteração de loop. O código de loop `threadData->strThread` poderia ter`str`sido escrito com todos os lugares ' é usado, mas o código seria muito mais lento na execução. É melhor fazer um cache de uma referência aos dados quando tais referências ocorrem em loops.

O `CThreadLocal` modelo de classe `CProcessLocal` usa os mesmos mecanismos que e as mesmas técnicas de implementação.

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
