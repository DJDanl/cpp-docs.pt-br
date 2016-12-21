---
title: "TN058: implementa&#231;&#227;o de estado do m&#243;dulo MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.mfc.implementation"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "DLLs [C++], estados de módulo"
  - "MFC [C++], gerenciando dados de estado"
  - "estados de módulo [C++], gerenciando dados de estado"
  - "estados de módulo [C++], alternando"
  - "estado de processo [C++]"
  - "estado de thread [C++]"
  - "TN058"
ms.assetid: 72f5b36f-b3da-4009-a144-24258dcd2b2f
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN058: implementa&#231;&#227;o de estado do m&#243;dulo MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que ela foi incluída pela primeira vez na documentação online.  Como resultado, alguns procedimentos e tópicos podem estar incorretos ou expirados.  Para obter as informações mais recentes, é recomendável que você procure o tópico de interesse no índice de documentação online.  
  
 Observe que essa técnica descreve a implementação do “de compilações de estado módulo” MFC.  Uma compreensão da implementação do estado do módulo é crítica para usar as dlls compartilhados MFC de uma DLL \(ou servidor OLE em processo\).  
  
 Antes de ler esta observe, consulte “gerenciando os dados do estado dos módulos de MFC” em [Criando novos documentos, windows, e exibições](../Topic/Creating%20New%20Documents,%20Windows,%20and%20Views.md).  Este artigo contém informações importantes de uso e informações de visão geral neste assunto.  
  
## Visão Geral  
 Há três tipos de informações do estado de MFC: Estado do módulo, estado do processo, e o estado do thread.  Às vezes esses tipos de estado podem ser combinados.  Por exemplo, mapas de identificador são MFC local do módulo e local do thread.  Isso permite que dois módulos diferentes têm mapas diferentes em cada um de seus threads.  
  
 O estado de processamento e o estado de thread são semelhantes.  Esses itens de dados são as coisas que foram tradicional variáveis globais, mas têm a necessidade de ser específicos para um processo ou a um determinado thread para suporte apropriado de Win32s ou para suporte de multithreading.  Categoria que um item de dados determinado depende se ajustar dentro desse item e sua semântica desejada em relação aos limites do processo e de thread.  
  
 O estado do módulo é exclusivo que pode conter o estado de fato global ou o indicar que é local do processo ou local do thread.  Além disso, é possível alternar rapidamente.  
  
## Alternar do estado do módulo  
 Cada thread contém um ponteiro para a “atual” ou “o estado ativo” de módulo \(não surpreendentemente, o ponteiro é parte do estado local do thread de MFC\).  Esse ponteiro é alterado quando o thread de execução passa um limite de módulo, como um aplicativo em um controlador OLE ou em uma DLL, ou uma chamada de OLE controlador de novo em um aplicativo.  
  
 O estado atual do módulo é alternado chamando **AfxSetModuleState**.  Em geral, você nunca tratará diretamente API.  O MFC, em muitos casos, você chamar\-o\-&z para \(em WinMain, por entrada em pontos OLE, em **AfxWndProc**, etc.\). Isso é feito em qualquer componente que escreva estaticamente vinculando em **WndProc**especial, e `WinMain` especial \(ou `DllMain`\) que sabe que estado atual do módulo deve ser.  Você pode consultar este código examinando DLLMODUL.CPP ou APPMODUL.CPP no diretório \\ SRC MFC.  
  
 É raro que você deseja definir o estado do módulo e não o definir volta.  Na maioria das vezes você deseja “para” empurrar seu próprio estado atual do módulo como e, depois de concluir,” a “aparecer novamente original de contexto.  Isso é feito por [AFX\_MANAGE\_STATE](../Topic/AFX_MANAGE_STATE.md) macro e pela classe especial **AFX\_MAINTAIN\_STATE**.  
  
 `CCmdTarget` tem recursos especiais para alternar de suporte do estado do módulo.  Em particular, `CCmdTarget` é a classe raiz usada para pontos DE automação OLE e de entrada COM OLE.  Como qualquer outro ponto de entrada expostos no sistema, esses pontos de entrada devem definir o estado correto do módulo.  Como `CCmdTarget` determinado souber qual o estado “correct” do módulo deve ser?  A resposta é que “registros” o que o estado “atual” do módulo é quando se cria, de modo que pode definir o estado atual do módulo ao valor “recordado” quando um é chamado posterior.  No, o estado do módulo que um determinado objeto de `CCmdTarget` é associado é o estado atual do módulo que estava quando o objeto foi construído.  Faça um exemplo simples de carregar um servidor de INPROC, de criar um objeto de chamar, e seus métodos.  
  
1.  A DLL é carregado por **LoadLibrary**do usando OLE.  
  
2.  **RawDllMain** é chamado primeiro.  Define o estado de módulo para o estado estático conhecido de módulo para a DLL.  **RawDllMain** é vinculado por esse motivo estaticamente para a DLL.  
  
3.  O construtor para a fábrica da classe associada com nosso objeto é chamado.  `COleObjectFactory` é derivado de `CCmdTarget` e no resultado, registros no qual estado do módulo foi criado uma instância do.  Isso é importante — quando a fábrica da classe for solicitada para criar objetos, souber que agora estado de módulo para fazer o atual.  
  
4.  `DllGetClassObject` é chamado para obter a fábrica da classe.  O MFC pesquisa a lista de fábrica da classe associada a esse módulo e retorná\-la.  
  
5.  **COleObjectFactory::XClassFactory2::CreateInstance** é chamado.  Antes de criar o objeto e de devolvê\-los, esta função define o estado de módulo para o estado atual do módulo que estava na etapa 3 \(o que era atual quando `COleObjectFactory` foi criado uma instância do\).  Isso é feito dentro de [METHOD\_PROLOGUE](../Topic/METHOD_PROLOGUE.md).  
  
6.  Quando o objeto é criado, é muito um derivado e da mesma forma `COleObjectFactory` de `CCmdTarget` recordados que o estado do módulo ativo, o que faz isso novo objeto.  Agora o objeto souber qual estado de módulo para alternar sempre que é chamado.  
  
7.  O cliente chama uma função no objeto COM o OLE receba de sua chamada de `CoCreateInstance` .  Quando o objeto é chamado usa `METHOD_PROLOGUE` para alternar o estado do módulo assim como faz `COleObjectFactory` .  
  
 Como você pode ver, o estado do módulo será propagado do objeto ao objeto conforme são criados.  É importante ter o estado do módulo definido adequadamente.  Se não for definido, o DLL ou objeto COM podem interagir precária com um aplicativo MFC o que está chamando, ou podem ser não é possível localizar seus próprios recursos, ou podem falhar em outras maneiras miseráveis.  
  
 Observe que determinados tipos de DLL, especificamente “DLL de extensão MFC” não retorne o estado do módulo no **RawDllMain** \(verdade, normalmente têm nem mesmo **RawDllMain**\).  Isso é porque visam se comportar “como” se realmente estavam presentes no aplicativo que usa o.  São many uma parte do aplicativo que está executando o e é a intenção alterar que o estado global do aplicativo.  
  
 Controladores OLE e outros DLL são muito diferentes.  Não deseja alterar o estado do aplicativo de chamada; o aplicativo que está chamando os não pode não podem ser um aplicativo MFC e portanto pode haver nenhum estado a ser modificado.  Esta é a razão pela qual alternar do estado do módulo esteve inventado.  
  
 Para funções exportadas de uma DLL, como um que inicia uma caixa de diálogo no DLL, adicione o seguinte código para o início da função:  
  
```  
AFX_MANAGE_STATE(AfxGetStaticModuleState( ))  
```  
  
 Isso alterna o estado atual do módulo com o estado retornado de [AfxGetStaticModuleState](../Topic/AfxGetStaticModuleState.md) até o final do escopo atual.  
  
 Os problemas com recursos na DLL ocorrerão se a macro de `AFX_MODULE_STATE` não é usado.  Por padrão, o MFC usa o identificador de recurso de aplicativo principal carregar o modelo de recursos.  Esse modelo é armazenado no DLL.  A causa raiz é que as informações de estado do módulo MFC não esteve alternada pela macro de `AFX_MODULE_STATE` .  O identificador de recurso são recuperadas do estado do módulo MFC.  Não alternar o estado do módulo faz com que a alça incorreta do recurso a ser usada.  
  
 `AFX_MODULE_STATE` não precisa ser colocado em cada função na DLL.  Por exemplo, `InitInstance` pode ser chamado pelo código de MFC no aplicativo sem `AFX_MODULE_STATE` porque o MFC alterna o estado automaticamente do módulo antes de `InitInstance` e depois é trocada ele novamente depois que `InitInstance` retorna.  O mesmo é válido para todos os manipuladores da mensagem.  Dlls normais têm realmente um procedimento de janela mestre especial que alternou o estado automaticamente do módulo antes de roteamento qualquer mensagem.  
  
## Dados do local do processo  
 Os dados locais do processo não seriam de uma grande preocupação sem dificuldade do modelo da DLL de Win32s.  Em todas as dlls de Win32s compartilhar seus dados globais, mesmo quando carregado por vários aplicativos.  Isso é muito diferente do modelo de dados “real” da DLL do Win32, onde cada DLL obtém uma cópia separada do espaço de dados em cada processo que é anexada à DLL.  Para adicionar à complexidade, os dados atribuídos no heap em uma DLL de Win32s são de fato específico do processo \(pelo menos tanto quanto a propriedade fica\).  Considere os seguintes dados e código:  
  
```  
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
  
 Considere o que acontece se o código anterior está localizado em uma DLL e que o DLL está carregado por dois processos A e B \(poderá, de fato, ser duas instâncias do mesmo aplicativo\).  Chamadas `SetGlobalString("Hello from A")`.  No resultado, a memória alocada para os dados de `CString` no contexto do processo A.  Lembre\-se de que `CString` próprio é global e é visível para a e a. B.  Agora B chama `GetGlobalString(sz, sizeof(sz))`.  B possa ver os dados que A definido.  Isso é porque Win32s não oferece nenhuma proteção entre processos como faz o Win32.  Esse é o primeiro problema; em muitos casos não é desejável ter um efeito global de dados de aplicativo que são considerados ser possuídos por um aplicativo diferente.  
  
 Há problemas adicionais também.  Vamos informar que A sair agora.  Quando A sair, a memória usada pela cadeia de caracteres de '`strGlobal`' é disponibilizada para o sistema \- ou seja, toda a memória alocada pelo processa A é liberada automaticamente pelo sistema operacional.  Não é liberada porque o destruidor de `CString` está sendo chamado; não foi chamada ainda.  É liberada simplesmente porque o aplicativo que a atribuído à esquerda de cena.  Agora se B chamou `GetGlobalString(sz, sizeof(sz))`, não é possível obter dados válidos.  Qualquer outro aplicativo pode usar essa memória para algo mais.  
  
 Claramente existe um problema.  O MFC 3.x usou uma técnica chamada armazenamento de thread local \(TLS\).  O MFC 3.x e um índice do TLS que em Win32s atuasse de fato como um índice de armazenamento do processo local, mesmo que não é chamado que o e em referenciaria todos os dados com base nesse índice do TLS.  Isso é semelhante ao índice do TLS que foi usado para armazenar dados de thread local no Win32 \(consulte abaixo para obter mais informações sobre esse assunto\).  Isso fez com que cada DLL MFC utilizasse pelo menos dois índices do TLS pelo processo.  Quando você carregar uma conta para muitos DLL do controlador OLE \(OCXs\), execute rapidamente fora dos índices do TLS \(há somente 64 disponíveis\).  Além disso, o MFC teve que colocar todos esses dados em um local, em uma única estrutura.  Não foi muito extensível e não era ideal em relação ao uso de índices do TLS.  
  
 MFC O 4.x resolve isso com um conjunto de modelos da classe que você pode envolver “” em torno dos dados que devem ser local do processo.  Por exemplo, o problema mencionado acima poderia ser corrigido para gravação:  
  
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
  
 MFC O implementa esse em duas etapas.  Primeiro, há uma camada sobre as APIs do Win32 **Tls\*** \(**TlsAlloc**, **TlsSetValue**, **TlsGetValue**, etc.\) que usam apenas dois índices do TLS pelo processo, não importando quantos DLL você possui.  Segundo, o modelo de `CProcessLocal` é fornecido para acessar esses dados.  Substitui o operador\> que é o que permite a sintaxe que ele você consulta anterior.  Todos os objetos envolvidos por `CProcessLocal` devem ser derivados de `CNoTrackObject`.  `CNoTrackObject` fornece um alocador de nível inferior \(**LocalAlloc**\/**LocalFree**\) e um destruidor virtual de modo que o MFC pode ser destruído automaticamente os objetos locais do processo quando o processo é encerrado.  Esses objetos podem ter um destruidor personalizado se a limpeza adicional é necessária.  O exemplo anterior não requer um, desde que o compilador gerará um destruidor padrão de destruir o objeto inserido de `CString` .  
  
 Há outras vantagens interessantes para essa abordagem.  Todos os objetos de `CProcessLocal` são destruídos não só automaticamente, eles não são construídos até que sejam necessários.  `CProcessLocal::operator->` criará uma instância do objeto associado a primeira vez que é chamado, e nenhum mais cedo.  No exemplo anterior, o que significa que a cadeia de caracteres de '`strGlobal`' não será construída até a primeira vez **SetGlobalString** ou **GetGlobalString** é chamado.  Em alguns casos, isso pode ajudar a reduzir o tempo de inicialização da DLL.  
  
## Dados do local do thread  
 Semelhante a dados locais do processo, dados locais de thread é usado quando os dados devem ser locais para um determinado thread.  Isto é, você precisa de uma instância separada de dados para cada thread que acessa esses dados.  Isso pode muitas vezes ser usado no lugar dos mecanismos extensos de sincronização.  Se os dados não precisam ser compartilhados por vários threads, esses mecanismos podem ser caros e desnecessários.  Suponha que nós tivemos um objeto de `CString` \(bem como o exemplo anterior\).  Podemos tornará o local do thread encapsulando\-os com um modelo de `CThreadLocal` :  
  
```  
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
      randErr = rand_s( &randomNumber );  
      if ( randErr == 0 )  
      {  
         TCHAR ch = randomNumber % 52 + 1;  
         if (str.Find(ch) < 0)  
            str += ch; // not found, add it  
      }  
   }  
}  
```  
  
 Se `MakeRandomString` foi chamado de dois threads diferentes, cada um “baralharia” a cadeia de caracteres de modos diferentes sem interferir com outros usuários.  Isso é porque há realmente uma instância de `strThread` pelo thread em vez de apenas uma instância global.  
  
 Observe como uma referência é usada para capturar uma vez o endereço de `CString` em vez de uma vez por iteração do loop.  O código de loop poderia ter sido escrita com `threadData->strThread` em qualquer parte '`str`' é usado, mas o código será muito mais lento na execução.  É melhor armazenar em cachê uma referência aos dados quando essas referências ocorrem em loop.  
  
 O modelo da classe de `CThreadLocal` usa os mesmos mecanismos que faz `CProcessLocal` e as mesmas técnicas de implementação.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)