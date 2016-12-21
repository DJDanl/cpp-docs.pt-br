---
title: "Classe de COleDocument | Microsoft Docs"
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
  - "COleDocument"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de COleDocument"
  - "documentos, O OLE"
  - "Contêiner VELHOS, itens de cliente"
  - "Documentos VELHOS"
  - "Documentos VELHOS, classe base"
  - "edição visual, A classe base OLE de documento"
ms.assetid: dc2ecb99-03e1-44c7-bb69-48056dd1b672
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleDocument
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe base para documentos VELHOS que oferecem suporte à edição visual.  
  
## Sintaxe  
  
```  
class COleDocument : public CDocument  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleDocument::COleDocument](../Topic/COleDocument::COleDocument.md)|Constrói um objeto de `COleDocument` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleDocument::AddItem](../Topic/COleDocument::AddItem.md)|Adiciona um item à lista de itens mantidos pelo documento.|  
|[COleDocument::ApplyPrintDevice](../Topic/COleDocument::ApplyPrintDevice.md)|Define o dispositivo de destino PRINT\- para todos os itens de cliente no documento.|  
|[COleDocument::EnableCompoundFile](../Topic/COleDocument::EnableCompoundFile.md)|Documentos das causas a serem armazenados usando o formato de arquivo de armazenamento estruturado OLE.|  
|[COleDocument::GetInPlaceActiveItem](../Topic/COleDocument::GetInPlaceActiveItem.md)|Retorna o item OLE que está atualmente ativa no lugar.|  
|[COleDocument::GetNextClientItem](../Topic/COleDocument::GetNextClientItem.md)|Obtém o próximo item de cliente para iterar.|  
|[COleDocument::GetNextItem](../Topic/COleDocument::GetNextItem.md)|Obtém o próximo item do documento para iterar.|  
|[COleDocument::GetNextServerItem](../Topic/COleDocument::GetNextServerItem.md)|Obtém o próximo item do servidor para iterar.|  
|[COleDocument::GetPrimarySelectedItem](../Topic/COleDocument::GetPrimarySelectedItem.md)|Retorna o OLE primária item selecionado no documento.|  
|[COleDocument::GetStartPosition](../Topic/COleDocument::GetStartPosition.md)|Obtém a posição inicial iniciar a iteração.|  
|[COleDocument::HasBlankItems](../Topic/COleDocument::HasBlankItems.md)|Verifica para itens em branco no documento.|  
|[COleDocument::OnShowViews](../Topic/COleDocument::OnShowViews.md)|Chamado quando o documento se torna visível ou invisível.|  
|[COleDocument::RemoveItem](../Topic/COleDocument::RemoveItem.md)|Remove um item da lista de itens mantidos pelo documento.|  
|[COleDocument::UpdateModifiedFlag](../Topic/COleDocument::UpdateModifiedFlag.md)|Marca o documento como modificado se qualquer um dos itens contidos VELHOS foram alterados.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleDocument::OnEditChangeIcon](../Topic/COleDocument::OnEditChangeIcon.md)|Trata eventos no comando de menu ícone de alteração.|  
|[COleDocument::OnEditConvert](../Topic/COleDocument::OnEditConvert.md)|Trata a conversão de um objeto inserido ou associado de um tipo para outro.|  
|[COleDocument::OnEditLinks](../Topic/COleDocument::OnEditLinks.md)|Os eventos de manipuladores nos links comando no menu de edição.|  
|[COleDocument::OnFileSendMail](../Topic/COleDocument::OnFileSendMail.md)|Envia uma mensagem de email com o documento anexado.|  
|[COleDocument::OnUpdateEditChangeIcon](../Topic/COleDocument::OnUpdateEditChangeIcon.md)|Chamado pela estrutura para atualizar o comando interface do usuário para a opção de menu do ícone de edição\/alteração.|  
|[COleDocument::OnUpdateEditLinksMenu](../Topic/COleDocument::OnUpdateEditLinksMenu.md)|Chamado pela estrutura para atualizar o comando interface do usuário para a opção de menu de edição\/links.|  
|[COleDocument::OnUpdateObjectVerbMenu](../Topic/COleDocument::OnUpdateObjectVerbMenu.md)|Chamado pela estrutura para atualizar o comando interface do usuário para a opção de menu de edição\/*ObjectName* e o submenu o verbo acessado de edição\/*ObjectName*.|  
|[COleDocument::OnUpdatePasteLinkMenu](../Topic/COleDocument::OnUpdatePasteLinkMenu.md)|Chamado pela estrutura para atualizar o comando interface do usuário para a opção de menu especial da pasta.|  
|[COleDocument::OnUpdatePasteMenu](../Topic/COleDocument::OnUpdatePasteMenu.md)|Chamado pela estrutura para atualizar o comando interface do usuário para a opção de menu da pasta.|  
  
## Comentários  
 `COleDocument` é derivado de **CDocument**, que permite seus aplicativos OLE usar a arquitetura do documento\/visualização fornecida pela biblioteca de classes da Microsoft foundation.  
  
 `COleDocument` trata um documento como uma coleção de objetos de [CDocItem](../../mfc/reference/cdocitem-class.md) para manipular itens VELHOS.  O contêiner e aplicativos de servidor requerem uma arquitetura pois os documentos devem ser capazes conter itens VELHOS.  As classes de [COleServerItem](../../mfc/reference/coleserveritem-class.md) e de [COleClientItem](../../mfc/reference/coleclientitem-class.md) , ambas derivadas de `CDocItem`, gerenciar as interações entre aplicativos e itens do OLE.  
  
 Se você estiver escrevendo um aplicativo simples de contêiner, derive sua classe de documento de `COleDocument`.  Se você estiver escrevendo um aplicativo de contêiner que suporte para vincular itens contidos inseridos pelos documentos, derive sua classe de documento de [COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md).  Se você estiver escrevendo um contêiner de aplicativo para servidores ou de combinação\/servidor, derive sua classe de documento de [COleServerDoc](../Topic/COleServerDoc%20Class.md).  `COleLinkingDoc` e `COleServerDoc` são derivados de `COleDocument`, para que essas classes herdam todos os serviços disponíveis em `COleDocument` e em **CDocument**.  
  
 Para usar `COleDocument`, derive uma classe de ele e adicionar funcionalidade para gerenciar os dados do OLE não do aplicativo assim como os itens inseridos ou associados.  Se você definir `CDocItem`\- classes derivadas para armazenar os dados nativos do aplicativo, você pode usar a implementação padrão definida por `COleDocument` para armazenar seus dados e não VELHOS do OLE.  Você também pode criar suas próprias estruturas de dados para armazenar os dados do OLE não separada dos itens VELHOS.  Para obter mais informações, consulte o artigo [Recipientes: arquivos compostos](../../mfc/containers-compound-files.md).  
  
 **CDocument** suporta seu documento enviar por email se o suporte de email \(MAPI\) está presente.  `COleDocument` atualizou [OnFileSendMail](../Topic/COleDocument::OnFileSendMail.md) para manipular corretamente documentos compostos.  Para obter mais informações, consulte os artigos [MAPI](../../mfc/mapi.md) e. [Suporte de MAPI no MFC](../../mfc/mapi-support-in-mfc.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CDocument](../Topic/CDocument%20Class.md)  
  
 `COleDocument`  
  
## Requisitos  
 **Cabeçalho:** afxole.h  
  
## Consulte também  
 [CONTÊINER de exemplo MFC](../../top/visual-cpp-samples.md)   
 [Exemplo MFCBIND MFC](../../top/visual-cpp-samples.md)   
 [Classe de CDocument](../Topic/CDocument%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)