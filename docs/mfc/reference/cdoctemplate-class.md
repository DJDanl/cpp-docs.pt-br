---
title: "Classe de CDocTemplate | Microsoft Docs"
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
  - "CDocTemplate"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDocTemplate"
  - "modelos de documento"
  - "modelos, documento"
ms.assetid: 14b41a1f-bf9d-4eac-b6a8-4c54ffcc77f6
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDocTemplate
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma classe base abstrata que define a funcionalidade básica para modelos do documento.  
  
## Sintaxe  
  
```  
class CDocTemplate : public CCmdTarget  
```  
  
## Membros  
  
### Construtores protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDocTemplate::CDocTemplate](../Topic/CDocTemplate::CDocTemplate.md)|Constrói um objeto de `CDocTemplate` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDocTemplate::AddDocument](../Topic/CDocTemplate::AddDocument.md)|Adiciona um documento em um modelo.|  
|[CDocTemplate::CloseAllDocuments](../Topic/CDocTemplate::CloseAllDocuments.md)|Fecha todos os documentos associados com esse modelo.|  
|[CDocTemplate::CreateNewDocument](../Topic/CDocTemplate::CreateNewDocument.md)|Cria um novo documento.|  
|[CDocTemplate::CreateNewFrame](../Topic/CDocTemplate::CreateNewFrame.md)|Cria uma nova janela do quadro que contém um documento e um modo de exibição.|  
|[CDocTemplate::CreateOleFrame](../Topic/CDocTemplate::CreateOleFrame.md)|Cria uma janela ativada OLE\- do quadro.|  
|[CDocTemplate::CreatePreviewFrame](../Topic/CDocTemplate::CreatePreviewFrame.md)|Cria um elemento filho usado para a visualização rico.|  
|[CDocTemplate::GetDocString](../Topic/CDocTemplate::GetDocString.md)|Recupera uma cadeia de caracteres associada com o tipo de documento.|  
|[CDocTemplate::GetFirstDocPosition](../Topic/CDocTemplate::GetFirstDocPosition.md)|Retorna a posição do primeiro documento associado com esse modelo.|  
|[CDocTemplate::GetNextDoc](../Topic/CDocTemplate::GetNextDoc.md)|Recupera um documento e a posição do seguir.|  
|[CDocTemplate::InitialUpdateFrame](../Topic/CDocTemplate::InitialUpdateFrame.md)|Inicializa a janela de quadro chave, e opcionalmente torna visível.|  
|[CDocTemplate::LoadTemplate](../Topic/CDocTemplate::LoadTemplate.md)|Carrega os recursos para `CDocTemplate` ou uma classe derivada fornecida.|  
|[CDocTemplate::MatchDocType](../Topic/CDocTemplate::MatchDocType.md)|Determina o grau de confiança na correspondência entre um tipo de documento e esse modelo.|  
|[CDocTemplate::OpenDocumentFile](../Topic/CDocTemplate::OpenDocumentFile.md)|Abre um arquivo especificado por um nome de caminho.|  
|[CDocTemplate::RemoveDocument](../Topic/CDocTemplate::RemoveDocument.md)|Remove um documento de um modelo.|  
|[CDocTemplate::SaveAllModified](../Topic/CDocTemplate::SaveAllModified.md)|Salva todos os documentos associados com esse modelo que foram alterados.|  
|[CDocTemplate::SetContainerInfo](../Topic/CDocTemplate::SetContainerInfo.md)|Determina os recursos para contêiners VELHOS ao editar um item OLE no lugar.|  
|[CDocTemplate::SetDefaultTitle](../Topic/CDocTemplate::SetDefaultTitle.md)|Exibe o título padrão na barra de título da janela do documento.|  
|[CDocTemplate::SetPreviewInfo](../Topic/CDocTemplate::SetPreviewInfo.md)|Configurações para o manipulador de visualização do processo.|  
|[CDocTemplate::SetServerInfo](../Topic/CDocTemplate::SetServerInfo.md)|Determina os recursos e as classes quando o documento de servidor é inserido ou editado no lugar.|  
  
## Comentários  
 Você normalmente cria um ou vários modelos de documento na implementação de função de `InitInstance` do seu aplicativo.  Um modelo de documento define as relações entre três tipos de classes:  
  
-   Uma classe de documento, que você derivar de **CDocument**.  
  
-   Uma classe de visualização, que exibe dados da classe do documento listados acima.  Você pode derivar essa classe de `CView`, de `CScrollView`, de `CFormView`, ou de `CEditView`.  \(Você também pode usar `CEditView` diretamente.\)  
  
-   Uma classe de janela do quadro, que contém o modo de exibição.  Para um aplicativo \(SDI\) da interface do documento único, você deriva de essa classe `CFrameWnd`.  Para um aplicativo de \(MDI\) de interface de documentos múltiplos, você deriva de essa classe `CMDIChildWnd`.  Se você não precisa personalizar o comportamento da janela do quadro, você pode usar `CFrameWnd` ou `CMDIChildWnd` diretamente sem derivar seus próprios classe.  
  
 Seu aplicativo tiver um modelo de documento para cada tipo de documento que suporta.  Por exemplo, se seu aplicativo suporta planilhas e documentos de texto, o aplicativo tem dois objetos de modelo do documento.  Cada modelo do documento é responsável para criar e gerenciar todos os documentos do tipo.  
  
 O modelo do documento armazena ponteiros para objetos de `CRuntimeClass` para o documento, a exibição, e as classes da janela do quadro.  Esses objetos de `CRuntimeClass` são especificados para criar um modelo do documento.  
  
 O modelo do documento contém a identificação dos recursos usados com o tipo de documento \(como o menu, o ícone, ou os recursos da tabela de aceleração.\)  O modelo do documento também tem as cadeias de caracteres que contêm informações adicionais sobre o tipo de documento.  Isso inclui o nome do tipo de documento \(por exemplo, “planilha”\) e a extensão de arquivo \(por exemplo, “.xls”\).  Opcionalmente, pode conter outras cadeias de caracteres usadas pela interface do usuário do aplicativo, pelo gerenciador de arquivos do windows, e o objeto de vinculação e inserindo o suporte do Object Linking and Embedding \(OLE\).  
  
 Se seu aplicativo é um contêiner e\/ou um servidor VELHOS, o modelo do documento também define a identificação do menu usado durante a ativação in\-loco.  Se seu aplicativo for um servidor, OLE o modelo do documento define a identificação da barra de ferramentas e de menu usados durante o ativação in\-loco.  Você especifica esses recursos adicionais VELHOS chamando `SetContainerInfo` e `SetServerInfo`.  
  
 Porque `CDocTemplate` é uma classe abstrata, você não pode usar a classe diretamente.  Um aplicativo típico usa um de dois `CDocTemplate`\- classes derivadas fornecidas pela biblioteca de classe de base da Microsoft: `CSingleDocTemplate`, que implementa o SDI, e `CMultiDocTemplate`, que implementa MDI.  Consulte as classes para obter mais informações sobre como usar modelos do documento.  
  
 Se seu aplicativo requer um paradigma da interface do usuário que é fundamentalmente diferente de SDI ou de MDI, você pode derivar sua própria classe de `CDocTemplate`.  
  
 Para obter mais informações sobre `CDocTemplate`, consulte [Modelos de documento e o processo de criação do documento\/exibição](../../mfc/document-templates-and-the-document-view-creation-process.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 `CDocTemplate`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [Classe de CCmdTarget](../Topic/CCmdTarget%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CSingleDocTemplate](../../mfc/reference/csingledoctemplate-class.md)   
 [Classe de CMultiDocTemplate](../../mfc/reference/cmultidoctemplate-class.md)   
 [Classe de CDocument](../Topic/CDocument%20Class.md)   
 [Classe de CView](../Topic/CView%20Class.md)   
 [Classe de CScrollView](../../mfc/reference/cscrollview-class.md)   
 [Classe de CEditView](../Topic/CEditView%20Class.md)   
 [Classe de CFormView](../../mfc/reference/cformview-class.md)   
 [Classe de CFrameWnd](../../mfc/reference/cframewnd-class.md)   
 [Classe de CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md)