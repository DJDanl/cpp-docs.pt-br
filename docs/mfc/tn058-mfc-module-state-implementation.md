---
title: 'TN058: Implementação de estado do módulo MFC | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.mfc.implementation
dev_langs:
- C++
helpviewer_keywords:
- thread state [MFC]
- module states [MFC], managing state data
- TN058
- MFC, managing state data
- module states [MFC], switching
- DLLs [MFC], module states
- process state [MFC]
ms.assetid: 72f5b36f-b3da-4009-a144-24258dcd2b2f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 90e407299f67922aa855a51b9983af074cdbd4fc
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33385746"
---
# <a name="tn058-mfc-module-state-implementation"></a>TN058: implementação de estado do módulo MFC
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 Essa observação técnica descreve a implementação de construções de "Estado do módulo MFC". Uma compreensão da implementação de estado do módulo é fundamental para usar o MFC compartilhado DLLs de uma DLL (ou no servidor OLE em processo).  
  
 Antes de ler esta anotação, consulte "Gerenciando a dados do estado dos módulos de MFC" na [criando novos documentos, janelas e modos de exibição](../mfc/creating-new-documents-windows-and-views.md). Este artigo contém informações de uso importantes e informações gerais sobre este assunto.  
  
## <a name="overview"></a>Visão geral  
 Há três tipos de informações de estado do MFC: estado do módulo, o estado do processo e o estado de Thread. Às vezes, esses tipos de estado podem ser combinados. Por exemplo, mapas de identificador do MFC são módulo local e o local de thread. Isso permite que dois módulos diferentes têm mapas diferentes em cada um dos seus threads.  
  
 Estado do processo e o estado de Thread são semelhantes. Esses itens de dados são coisas que normalmente são variáveis globais, mas que precisem ser específico para um determinado processo ou thread de Win32s apropriado de suporte ou para suporte a multithreading adequado. Qual categoria se ajusta a um item de dados determinado depende desse item e sua semântica desejada em relação a limites de processos e threads.  
  
 Estado do módulo é exclusivo e pode conter estado realmente global ou estado de processo local ou local de thread. Além disso, ele pode ser alternado rapidamente.  
  
## <a name="module-state-switching"></a>Alternância de estado do módulo  
 Cada thread contém um ponteiro para o estado do módulo "atual" ou "ativos" (não surpreendentemente, o ponteiro é parte do estado de local de thread do MFC). Esse ponteiro é alterado quando o thread de execução passa um limite de módulo, como um aplicativo de chamada em um controle OLE ou DLL ou um controle OLE chamar de volta em um aplicativo.  
  
 O estado atual do módulo é alternado chamando **AfxSetModuleState**. A maior parte do tempo, você nunca será lidar diretamente com a API. MFC, em muitos casos, irá chamá-lo para você (em WinMain, pontos de entrada do OLE, **AfxWndProc**, etc.). Isso é feito em qualquer componente que você escreve a vinculação estática em especial **WndProc**e um especial `WinMain` (ou `DllMain`) que sabe qual estado do módulo deve ser atual. Você pode ver esse código examinando DLLMODUL. CPP ou APPMODUL. CPP no diretório MFC\SRC.  
  
 É raro que você deseja definir o estado do módulo e não configura-o novamente. Na maioria das vezes de que você deseja "push" de seu próprio módulo estado que o atual e, em seguida, depois de concluir, "pop" novamente o contexto original. Isso é feito pela macro [AFX_MANAGE_STATE](reference/extension-dll-macros.md#afx_manage_state) e a classe especial **AFX_MAINTAIN_STATE**.  
  
 `CCmdTarget` tem recursos especiais para dar suporte a alternância de estado do módulo. Em particular, um `CCmdTarget` é a classe raiz usado para automação OLE e o OLE COM pontos de entrada. Como qualquer outro ponto de entrada exposto ao sistema, esses pontos de entrada devem definir o estado do módulo correto. Como does um determinado `CCmdTarget` saber qual o estado do módulo "correto" deve ser a resposta é que ela "lembra" o que é o estado "atual" do módulo quando ele é construído, que pode definir o estado atual do módulo para que "lembradas" chamado valor quando for posterior. Como resultado, o módulo de estado que um determinado `CCmdTarget` objeto está associado com é o estado do módulo que era o atual quando o objeto foi construído. Veja um exemplo simple de um servidor INPROC de carregamento, criação de um objeto e chamar seus métodos.  
  
1.  A DLL é carregada pelo OLE usando **LoadLibrary**.  
  
2. **RawDllMain** é chamado primeiro. Ele define o estado do módulo para o estado do módulo estático conhecido para a DLL. Por esse motivo **RawDllMain** está estaticamente vinculada à DLL.  
  
3.  O construtor para a fábrica de classes associada com nosso objeto é chamado. `COleObjectFactory` é derivado de `CCmdTarget` e como resultado, ele se lembra de em qual estado do módulo que ele foi instanciado. Isso é importante — quando for solicitada a fábrica de classes para criar objetos, agora sabe qual estado do módulo a ser o atual.  
  
4. `DllGetClassObject` é chamado para obter a fábrica de classes. MFC procura a lista de fábrica de classe associada a este módulo e o retorna.  
  
5. **COleObjectFactory::XClassFactory2::CreateInstance** é chamado. Antes de criar o objeto e retorná-lo, essa função define o estado do módulo para o estado do módulo que era atual na etapa 3 (que era o atual quando o `COleObjectFactory` foi instanciado). Isso é feito dentro de [METHOD_PROLOGUE](com-interface-entry-points.md).  
  
6.  Quando o objeto é criado, ele também é um `CCmdTarget` derivados e da mesma forma `COleObjectFactory` lembradas qual estado do módulo estava ativo, aumenta esse novo objeto. Agora que o objeto sabe qual estado do módulo para alternar para sempre que ele é chamado.  
  
7.  O cliente chama uma função no objeto OLE COM recebido do seu `CoCreateInstance` chamar. Quando o objeto é chamado, ele usa `METHOD_PROLOGUE` para alternar o estado do módulo como `COleObjectFactory` does.  
  
 Como você pode ver, o estado do módulo é propagado de objeto ao objeto conforme eles são criados. É importante ter o estado de módulo definido adequadamente. Se não for definido, o objeto DLL ou COM pode interagir mal com um aplicativo MFC que está chamando, ou pode não conseguir localizar seus próprios recursos ou pode falhar em outras maneiras péssima.  
  
 Observe que certos tipos de DLLs, especificamente as DLLs de "extensão do MFC" não alternar o estado do módulo em seus **RawDllMain** (na verdade, eles geralmente não ainda têm um **RawDllMain**). Isso ocorre porque elas pretendem se comportam "como se" estivessem realmente presentes no aplicativo que usa. Eles são muito uma parte do aplicativo que está sendo executado e é sua intenção de modificar o estado global do aplicativo.  
  
 Controles OLE e outras DLLs são muito diferentes. Não desejam modificar o estado do aplicativo de chamada. o aplicativo que está chamando não pode ser até mesmo um aplicativo MFC e portanto não pode haver nenhum estado para modificar. Este é o motivo que a alternância de estado do módulo foi criado.  
  
 Para funções exportadas de uma DLL, por exemplo, um que inicia uma caixa de diálogo na DLL, você precisa adicionar o código a seguir para o início da função:  
  
```  
AFX_MANAGE_STATE(AfxGetStaticModuleState())  
```  
  
 Isso alterna o estado atual do módulo com o estado retornado de [AfxGetStaticModuleState](reference/extension-dll-macros.md#afxgetstaticmodulestate) até o término do escopo atual.  
  
 Problemas com recursos em DLLs ocorrerá se o `AFX_MODULE_STATE` macro não é usada. Por padrão, o MFC usa o identificador de recurso do aplicativo principal para carregar o modelo de recurso. Este modelo, na verdade, é armazenado na DLL. A causa raiz é que informações de estado do módulo do MFC não foi alternadas pelo `AFX_MODULE_STATE` macro. O identificador de recurso é recuperado do estado do módulo do MFC. Não mudar o estado do módulo faz com que o identificador de recurso incorreto ser usado.  
  
 `AFX_MODULE_STATE` não precisa ser colocado em cada função na DLL. Por exemplo, `InitInstance` pode ser chamado pelo código do aplicativo sem MFC `AFX_MODULE_STATE` porque MFC automaticamente muda o estado do módulo antes de `InitInstance` e, em seguida, os comutadores novamente após `InitInstance` retorna. O mesmo vale para todos os manipuladores de mapa de mensagem. DLLs normais do MFC realmente tem um procedimento de janela mestre especial que alterna automaticamente o estado do módulo antes de encaminhar uma mensagem.  
  
## <a name="process-local-data"></a>Dados locais do processo  
 Processar dados de local não seria tais grande preocupação ele não tivesse sido para a dificuldade de modelo Win32s DLL. No Win32s todas as DLLs compartilham seus dados globais, até mesmo quando carregado por vários aplicativos. Isso é muito diferente do modelo de dados DLL Win32 "real", onde cada DLL obtém uma cópia separada do seu espaço de dados em cada processo que anexa à DLL. Para adicionar complexidade, dados alocados no heap em uma DLL Win32s são na verdade processo específico (pelo menos até onde vai de propriedade). Considere os seguintes dados e código:  
  
```  
static CString strGlobal; // at file scope  
 
__declspec(dllexport)   
void SetGlobalString(LPCTSTR lpsz)  
{  
    strGlobal = lpsz;  
}  
 
__declspec(dllexport)  
void GetGlobalString(LPCTSTR lpsz,
    size_t cb)  
{  
    StringCbCopy(lpsz,
    cb,
    strGlobal);

}  
```  
  
 Considere o que acontece se o código acima em estará em uma DLL e que a DLL é carregada por dois processos A e B (pode, na verdade, ser duas instâncias do mesmo aplicativo). Um chamadas `SetGlobalString("Hello from A")`. Como resultado, a memória alocada para o `CString` os dados no contexto do processo de r. Lembre-se de que o `CString` em si é global e é visível para os dois A e b. Agora B chama `GetGlobalString(sz, sizeof(sz))`. B poderão ver os dados que um conjunto. Isso ocorre porque Win32s não oferece proteção entre processos, como o Win32. Esse é o primeiro problema; em muitos casos não é desejável ter um aplicativo de afetar os dados globais que são considerados para pertencer a um aplicativo diferente.  
  
 Há também problemas adicionais. Digamos que um agora será encerrado. Quando um é encerrado, a memória usada pelo '`strGlobal`' cadeia de caracteres é disponibilizada para o sistema — ou seja, toda a memória alocada por um processo é liberada automaticamente pelo sistema operacional. Não é liberada porque o `CString` destruidor está sendo chamado; ele não foi chamado. Liberado simplesmente porque o aplicativo que alocou saiu da cena. Agora, se B chamado `GetGlobalString(sz, sizeof(sz))`, ele não pode receber dados válidos. Outro aplicativo pode ter usado o que a memória para outra coisa.  
  
 Claramente um problema existe. MFC 3. x usado uma técnica chamada armazenamento local de thread (TLS). MFC 3. x alocará um índice TLS que atua como um índice de armazenamento local de processo, de fato em Win32s, embora não seja chamado que e, em seguida, deve fazer referência a todos os dados com base no índice TLS. Isso é semelhante ao índice TLS que foi usado para armazenar dados de local de thread Win32 (consulte abaixo para obter mais informações sobre o assunto). Isso causou cada DLL do MFC utilizar pelo menos dois índices TLS por processo. Quando você conta para DLLs de carregamento muitos OLE controle (OCXs), você rapidamente ficar sem índices TLS (são apenas 64 disponível). Além disso, o MFC tinha colocar todos os dados em um só lugar, em uma única estrutura. Não foi muito extensível e não era ideal em relação ao seu uso de índices TLS.  
  
 MFC 4. x lida com isso com um conjunto de modelos de classe, você pode "encapsular" em torno dos dados que devem ser um processo local. Por exemplo, o problema mencionado acima pode ser corrigido por meio da gravação:  
  
```  
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
  
 MFC implementa em duas etapas. Primeiro, há uma camada na parte superior do Win32 **Tls\***  APIs (**TlsAlloc**, **TlsSetValue**, **TlsGetValue**, etc.) que Use apenas dois índices TLS por processo, não importa quantas DLLs que você tem. Segundo, o `CProcessLocal` modelo é fornecido para acessar esses dados. Ela substitui o operador -> que é o que permite a sintaxe intuitiva que você vê acima. Todos os objetos que são quebrados pelo `CProcessLocal` deve ser derivado de `CNoTrackObject`. `CNoTrackObject` Fornece um alocador de nível inferior (**LocalAlloc**/**LocalFree**) e um destruidor virtual, de modo que MFC automaticamente pode destruir os objetos de processo local quando o processo foi finalizado. Esses objetos podem ter um destruidor personalizado se a limpeza adicional é necessária. O exemplo acima não requer um, desde que o compilador gerará um destruidor padrão para destruir o embedded `CString` objeto.  
  
 Há outras vantagens dessa abordagem interessantes. Não só são todos `CProcessLocal` objetos destruídos automaticamente, eles não são criados até que eles são necessários. `CProcessLocal::operator->` instanciará o objeto associado na primeira vez que ele é chamado e não antes. No exemplo acima, isso significa que o '`strGlobal`' cadeia de caracteres não será construída até a primeira vez **SetGlobalString** ou **GetGlobalString** é chamado. Em alguns casos, isso pode ajudar a reduzir o tempo de inicialização da DLL.  
  
## <a name="thread-local-data"></a>Dados de Local de thread  
 Semelhante ao processar dados locais, dados de local de thread são usados quando os dados devem ser locais para um determinado thread. Ou seja, você precisa de uma instância separada dos dados para cada thread que acessa dados. Isso pode muitas vezes ser usado em vez de mecanismos de sincronização abrangente. Se os dados não precisam ser compartilhado por vários threads, esses mecanismos podem ser desnecessário e caro. Suponha que tivemos um `CString` objeto (muito parecida com o exemplo acima). Podemos pode torná-la de thread local encapsulá-lo com um `CThreadLocal` modelo:  
  
```  
struct CMyThreadData : public CNoTrackObject  
{  
    CString strThread;  
};  
CThreadLocal<CMyThreadData> threadData;  
 
void MakeRandomString()  
{ *// a kind of card shuffle (not a great one)  
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
  
 Se `MakeRandomString` foi chamado de dois threads diferentes, cada seria "em ordem aleatória" a cadeia de caracteres de maneiras diferentes sem interferir com o outro. Isso ocorre porque há realmente um `strThread` instância por thread em vez de apenas uma instância global.  
  
 Observe como uma referência é usada para capturar o `CString` endereço uma vez, em vez de uma vez por iteração do loop. O código de loop foi gravado com `threadData->strThread` everywhere '`str`' for usado, mas o código seria muito mais lento em execução. É melhor para armazenar em cache uma referência aos dados quando essas referências ocorrem em loops.  
  
 O `CThreadLocal` template de classe usa os mesmos mecanismos que `CProcessLocal` não e as mesmas técnicas de implementação.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

