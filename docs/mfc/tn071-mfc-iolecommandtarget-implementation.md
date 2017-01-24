---
title: "TN071: implementa&#231;&#227;o de IOleCommandTarget MFC | Microsoft Docs"
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
  - "IOleCommandTarget"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Interface IOleCommandTarget"
  - "TN071"
ms.assetid: 3eef571e-6357-444d-adbb-6f734a0c3161
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN071: implementa&#231;&#227;o de IOleCommandTarget MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que ela foi incluída pela primeira vez na documentação online.  Como resultado, alguns procedimentos e tópicos podem estar incorretos ou expirados.  Para obter as informações mais recentes, é recomendável que você procure o tópico de interesse no índice de documentação online.  
  
 A interface de `IOleCommandTarget` habilita objetos e seus contêineres a expedição comando entre si.  Por exemplo, as barras de ferramentas de um objeto pode conter os botões para comandos como **Imprimir**, **Visualizar Impressão**, **Salvar**, `New`, e **Zoom**.  Se esse objeto foi inserido em um contêiner que da suporte a `IOleCommandTarget`, o objeto pode habilitar os botões e encaminhar os comandos ao contêiner para processar quando o usuário clicou nos.  Se um contêiner queria o objeto inserido para se imprimir, pode fazer essa solicitação ao enviar um comando por meio da interface de `IOleCommandTarget` do objeto inserido.  
  
 `IOleCommandTarget` é Automação\- como a interface usada por um cliente para invocar métodos em um servidor.  Porém, usando `IOleCommandTarget` salva a sobrecarga de fazer chamadas por meio das interfaces de automação como os programadores não precisam usar o método normalmente caro de `Invoke` de `IDispatch`.  
  
 MFC no, a interface de `IOleCommandTarget` é usada por servidores ativas do documento para permitir que os contêineres ativas do documento despachem comandos ao servidor.  A classe do servidor ativo do documento, `CDocObjectServerItem`, mapas da interface de MFC do \(consulte [TN038: Implementação de MFC\/OLE IUnknown](../mfc/tn038-mfc-ole-iunknown-implementation.md)\) para implementar a interface de `IOleCommandTarget` .  
  
 `IOleCommandTarget` é implementado da classe de **COleFrameHook** .  **COleFrameHook** é uma classe não documentado MFC que implementa a funcionalidade da janela do quadro de contêineres de edição no local.  **COleFrameHook** também usa mapas da interface de MFC para implementar a interface de `IOleCommandTarget` .  A implementação de**COleFrameHook** de `IOleCommandTarget` encaminha comandos DE a `COleDocObjectItem`\- contêiner ativas derivados do documento.  Isso permite a qualquer MFC o contêiner ativa do documento receba mensagens de servidores ativas independentes do documento.  
  
## Mapas de comando OLE MFC  
 Os desenvolvedores de MFC podem tirar proveito de `IOleCommandTarget` usando mapas com OLE DB do comando MFC.  Os mapas com OLE DB de comando são como mapas de mensagem como podem ser usados para mapear comandos DE as funções de membro da classe que contém o mapa do comando.  Para fazer isso, macros de trabalho local no mapa de comando para especificar o grupo de comando OLE de comando que você deseja manipular, o comando OLE, e a ID de comando da mensagem de [WM\_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) que será enviada quando o comando OLE é recebido.  MFC O também fornece um número de macros predefinidos para comandos do padrão.  Para obter uma lista dos comandos do padrão que foi criado originalmente para uso com aplicativos do Microsoft Office, consulte a enumeração de OLECMDID, que é definida em docobj.h.  
  
 Quando um comando OLE é recebido por um aplicativo MFC que contém um mapa de comando OLE MFC, o tenta localizar o grupo de ID de comando e de comando para o comando solicitado no mapa de comando OLE do aplicativo.  Se for encontrada uma correspondência, uma mensagem de **WM\_COMMAND** foi despachada ao aplicativo que contém o mapa de comando com a ID do comando solicitado. \(Consulte a descrição de `ON_OLECMD` em.\) Desse modo, os comandos OLE despachados para um aplicativo são transformados em mensagens de **WM\_COMMAND** por MFC.  As mensagens de **WM\_COMMAND** são roteadas pelos mapas da mensagem do aplicativo com a arquitetura padrão [roteamento de comando](../mfc/command-routing.md) MFC.  
  
 Diferentemente dos mapas da mensagem, mapas com OLE DB do comando MFC não têm suporte ClassWizard.  Os desenvolvedores de MFC deve adicionar suporte OLE do mapa de comando e entradas com OLE DB do mapa de comando para a mão.  Os mapas com OLE DB de comando podem ser adicionados aos servidores ativas do documento MFC em qualquer classe que estiver na cadeia retornadas roteamento de **WM\_COMMAND** no momento em que o documento ativo está ativa no local em um contêiner.  Essas classes incluem as classes derivadas do aplicativo de [CWinApp](../mfc/reference/cwinapp-class.md), de [CView](../Topic/CView%20Class.md), de [CDocument](../Topic/CDocument%20Class.md), e de [COleIPFrameWnd](../mfc/reference/coleipframewnd-class.md).  Em contêineres ativas do documento, mapas com OLE DB do comando só podem ser adicionados a [COleDocObjectItem](../Topic/COleDocObjectItem%20Class.md)\- classe derivada.  Além disso, em contêineres ativas do documento, as mensagens de **WM\_COMMAND** serão despachadas somente ao mapa em `COleDocObjectItem`\- classe derivada da mensagem.  
  
## Macros OLE DB do mapa de comando  
 Use os seguintes macros para adicionar funcionalidade do mapa de comando para sua classe:  
  
```  
  
DECLARE_OLECMD_MAP ()  
  
```  
  
 Esta macro vai na declaração de classe \(normalmente no arquivo de cabeçalho\) da classe que contém o mapa do comando.  
  
```  
  
BEGIN_OLECMD_MAP(  
theClass  
,   
baseClass  
)  
  
```  
  
 `theClass`  
 Nome da classe que contém o mapa do comando.  
  
 `baseClass`  
 Nome da classe base da classe que contém o mapa do comando.  
  
 Esta macro marca o início do mapa de comando.  Use esta macro no arquivo de implementação da classe que contém o mapa de comando.  
  
```  
  
END_OLECMD_MAP()  
  
```  
  
 Esta macro marca o fim do mapa de comando.  Use esta macro no arquivo de implementação da classe que contém o mapa de comando.  Esta macro sempre deve obedecer a macro de **BEGIN\_OLECMD\_MAP** .  
  
```  
  
ON_OLECMD(  
pguid  
,   
olecmdid  
,   
id  
)  
  
```  
  
 `pguid`  
 Ponteiro para o GUID do grupo de comando OLE do comando.  Esse parâmetro é **nulo** para o grupo de comando OLE padrão.  
  
 *olecmdid*  
 ID do comando OLE do comando ser invocado.  
  
 `id`  
 ID da mensagem de **WM\_COMMAND** a ser enviada ao aplicativo que contém o mapa de comando quando este comando OLE for invocado.  
  
 Use a macro de `ON_OLECMD` no mapa de comando para adicionar entradas para os comandos DE que você deseja controlar.  Quando os comandos OLE são recebidos, eles serão convertidos a mensagem especificada de **WM\_COMMAND** e retornado por meio da mensagem de aplicativo usando a arquitetura de comando\- roteamento MFC do padrão.  
  
## Exemplo  
 O exemplo a seguir mostra como adicionar o recurso OLE de comando\- manipulação a um servidor ativo do documento MFC tratar o comando OLE de [OLECMDID\_PRINT](http://msdn.microsoft.com/library/windows/desktop/ms691264) .  Este exemplo supõe que você usou AppWizard para gerar um aplicativo MFC que é um servidor ativo do documento.  
  
1.  No `CView`\- o arquivo de cabeçalho derivado da classe, adiciona a macro de `DECLARE_OLECMD_MAP` à declaração da classe.  
  
    > [!NOTE]
    >  Use `CView`\- classe derivada porque é uma das classes no servidor ativo do documento que está na cadeia retornadas roteamento de **WM\_COMMAND** .  
  
    ```  
    class CMyServerView : public CView  
    {  
    protected: // create from serialization only  
       CMyServerView();  
       DECLARE_DYNCREATE(CMyServerView)  
       DECLARE_OLECMD_MAP()  
    . . .  
    };  
    ```  
  
2.  No arquivo de implementação de `CView`\- a classe derivada, adiciona as macros de `BEGIN_OLECMD_MAP` e de `END_OLECMD_MAP` :  
  
    ```  
    BEGIN_OLECMD_MAP(CMyServerView, CView)  
  
    END_OLECMD_MAP()  
    ```  
  
3.  Para tratar o comando de OLE cópia padrão, adicione uma macro de [ON\_OLECMD](../Topic/ON_OLECMD.md) ao mapa do comando especificando o ID do comando OLE para o comando de cópia e **ID\_FILE\_PRINT** padrão para a ID de **WM\_COMMAND ID\_FILE\_PRINT** é a ID de comando padrão de cópia usado por aplicativos AppWizard\- gerados MFC:  
  
    ```  
    BEGIN_OLECMD_MAP(CMyServerView, CView)  
       ON_OLECMD(NULL,OLECMDID_PRINT,ID_FILE_PRINT)  
    END_OLECMD_MAP()  
    ```  
  
 Observe que o de macros de comando OLE padrão, definido em afxdocob.h, pode ser usado no lugar de macro de `ON_OLECMD` porque **OLECMDID\_PRINT** é uma ID de comando OLE padrão  A macro de `ON_OLECMD_PRINT` realizará a mesma tarefa que a macro de `ON_OLECMD` mostrado acima.  
  
 Quando um aplicativo de contêiner esse servidor envia um comando de **OLECMDID\_PRINT** por meio da interface de `IOleCommandTarget` do servidor, o manipulador do comando de impressão MFC será invocado no servidor, fazendo com que o servidor imprimir o aplicativo.  O código ativa do contêiner do documento para invocar o comando copiar adicionado nas etapas acima seria algo como:  
  
```  
void CContainerCntrItem::DoOleCmd()  
{  
   IOleCommandTarget *pCmd = NULL;  
   HRESULT hr = E_FAIL;  
   OLECMD ocm={OLECMDID_PRINT, 0};  
  
   hr = m_lpObject->QueryInterface(IID_IOleCommandTarget,reinterpret_cast<void**>(&pCmd));  
   if(FAILED(hr))  
      return;  
  
   hr = pCmd->QueryStatus(NULL, 1, &ocm, NULL);  
   if(SUCCEEDED(hr) && (ocm.cmdf & OLECMDF_ENABLED))  
   {  
      //Command is available and enabled so call it  
      COleVariant vIn;  
      COleVariant vOut;  
      hr = pCmd->Exec(NULL, OLECMDID_PRINT,  
 OLECMDEXECOPT_DODEFAULT, &vIn, &vOut);  
      ASSERT(SUCCEEDED(hr));  
   }  
   pCmd->Release();  
}  
```  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)