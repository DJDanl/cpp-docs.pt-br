---
title: "Classe de COleLinkingDoc | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "COleLinkingDoc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de COleLinkingDoc"
  - "Contêiner VELHOS, itens de cliente"
ms.assetid: 9f547f35-2f95-427f-b9c0-85c31940198b
caps.latest.revision: 24
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleLinkingDoc
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe base para documentos contêiner VELHOS que suportam vincular aos itens inseridos contêm.  
  
## Sintaxe  
  
```  
class COleLinkingDoc : public COleDocument  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleLinkingDoc::COleLinkingDoc](../Topic/COleLinkingDoc::COleLinkingDoc.md)|Constrói um objeto de `COleLinkingDoc` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleLinkingDoc::Register](../Topic/COleLinkingDoc::Register.md)|Registra o documento com as dlls VELHOS do sistema.|  
|[COleLinkingDoc::Revoke](../Topic/COleLinkingDoc::Revoke.md)|Revoga o registro do documento.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleLinkingDoc::OnFindEmbeddedItem](../Topic/COleLinkingDoc::OnFindEmbeddedItem.md)|Localiza o item inserido especificado.|  
|[COleLinkingDoc::OnGetLinkedItem](../Topic/COleLinkingDoc::OnGetLinkedItem.md)|Localiza o item associado especificado.|  
  
## Comentários  
 Um aplicativo de contêiner que suporte para vincular itens inseridos é chamado de “contêiner um link.” O aplicativo de exemplo [OCLIENT](../../top/visual-cpp-samples.md) é um exemplo de um contêiner de link.  
  
 Quando a fonte de um item associado é um item inserido em outro documento, esse documento recipiente deve ser carregado para o item inserido ser editado.  Por esse motivo, um contêiner de link deve poder ser iniciado por outro aplicativo de contêiner quando o usuário deseja editar a fonte de um item associado.  O aplicativo também deve usar a classe de [COleTemplateServer](../../mfc/reference/coletemplateserver-class.md) de modo que pode criar documentos quando iniciado por meio de programação.  
  
 Para fazer ao recipiente um contêiner de link, sua classe derivada de documento de `COleLinkingDoc` em vez de [COleDocument](../../mfc/reference/coledocument-class.md).  Como com qualquer outro contêiner OLE, você deve criar sua classe para armazenar os dados nativos bem como os itens inseridos ou associados do aplicativo.  Além de isso, você deve criar estruturas de dados para armazenar seus dados nativos.  Se você definir `CDocItem`\- classe derivada para os dados nativos do seu aplicativo, você pode usar a interface definida por `COleDocument` para armazenar seus dados nativos bem como seus dados VELHOS.  
  
 Para permitir que o aplicativo é iniciado programaticamente por outro contêiner, declare um objeto de `COleTemplateServer` como um membro de `CWinApp`do aplicativo \- classe derivada:  
  
 [!code-cpp[NVC_MFCOleContainer#23](../../mfc/reference/codesnippet/CPP/colelinkingdoc-class_1.h)]  
  
 Em a função de membro do `CWinApp`\- classe derivada de `InitInstance` , crie um modelo de documento e especifique seu `COleLinkingDoc`\- classe derivada como a classe de documento:  
  
 [!code-cpp[NVC_MFCOleContainer#24](../../mfc/reference/codesnippet/CPP/colelinkingdoc-class_2.cpp)]  
  
 Conectar seu objeto de `COleTemplateServer` a seus modelos de documentos pela função de membro de `ConnectTemplate` do objeto, e registrar todos os objetos da classe com o sistema OLE chamando **COleTemplateServer::RegisterAll**:  
  
 [!code-cpp[NVC_MFCOleContainer#25](../../mfc/reference/codesnippet/CPP/colelinkingdoc-class_3.cpp)]  
  
 Para um exemplo `CWinApp`\- a definição de classe derivada e a função de `InitInstance` , consulte OCLIENT.H e OCLIENT.CPP no exemplo [OCLIENT](../../top/visual-cpp-samples.md)MFC.  
  
 Para obter mais informações sobre como usar `COleLinkingDoc`, consulte os artigos [Recipientes: implementando um contêiner](../../mfc/containers-implementing-a-container.md) e [Recipientes: recursos avançados](../../mfc/containers-advanced-features.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CDocument](../Topic/CDocument%20Class.md)  
  
 [COleDocument](../../mfc/reference/coledocument-class.md)  
  
 `COleLinkingDoc`  
  
## Requisitos  
 **Cabeçalho:** afxole.h  
  
## Consulte também  
 [Exemplo OCLIENT MFC](../../top/visual-cpp-samples.md)   
 [Classe de COleDocument](../../mfc/reference/coledocument-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CDocTemplate](../../mfc/reference/cdoctemplate-class.md)