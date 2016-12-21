---
title: "Classe de COlePasteSpecialDialog | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "COlePasteSpecialDialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de COlePasteSpecialDialog"
  - "caixas de diálogo, Colar Especial"
  - "Caixa de diálogo da pasta especial do OLE"
  - "Caixa de diálogo especial da pasta"
ms.assetid: 0e82ef9a-9bbe-457e-8240-42c86a0534f7
caps.latest.revision: 24
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COlePasteSpecialDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado para a caixa de diálogo do OLE especial da pasta.  
  
## Sintaxe  
  
```  
  
class COlePasteSpecialDialog : public COleDialog  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COlePasteSpecialDialog::COlePasteSpecialDialog](../Topic/COlePasteSpecialDialog::COlePasteSpecialDialog.md)|Constrói um objeto de `COlePasteSpecialDialog` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COlePasteSpecialDialog::AddFormat](../Topic/COlePasteSpecialDialog::AddFormat.md)|Adiciona formatos personalizados à lista de formatos que seu aplicativo pode colar.|  
|[COlePasteSpecialDialog::AddLinkEntry](../Topic/COlePasteSpecialDialog::AddLinkEntry.md)|Adiciona uma nova entrada à lista de formatos suporte da área de transferência.|  
|[COlePasteSpecialDialog::AddStandardFormats](../Topic/COlePasteSpecialDialog::AddStandardFormats.md)|Adiciona **CF\_BITMAP**, **CF\_DIB**, `CF_METAFILEPICT`e, opcionalmente `CF_LINKSOURCE` à lista de formatos que seu aplicativo pode colar.|  
|[COlePasteSpecialDialog::CreateItem](../Topic/COlePasteSpecialDialog::CreateItem.md)|Cria o item no contêiner documento usando o formato especificado.|  
|[COlePasteSpecialDialog::DoModal](../Topic/COlePasteSpecialDialog::DoModal.md)|Exibe a caixa de diálogo do OLE especial da pasta.|  
|[COlePasteSpecialDialog::GetDrawAspect](../Topic/COlePasteSpecialDialog::GetDrawAspect.md)|Informa se o item como desenhar um ícone ou não.|  
|[COlePasteSpecialDialog::GetIconicMetafile](../Topic/COlePasteSpecialDialog::GetIconicMetafile.md)|Obtém um manipulador para o metarquivo associado ao formulário icónico de este item.|  
|[COlePasteSpecialDialog::GetPasteIndex](../Topic/COlePasteSpecialDialog::GetPasteIndex.md)|Obtém o índice das opções disponíveis de pasta que foi escolhida pelo usuário.|  
|[COlePasteSpecialDialog::GetSelectionType](../Topic/COlePasteSpecialDialog::GetSelectionType.md)|Obtém o tipo de seleção escolhido.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[COlePasteSpecialDialog::m\_ps](../Topic/COlePasteSpecialDialog::m_ps.md)|Uma estrutura do tipo **OLEUIPASTESPECIAL** que controla a função da caixa de diálogo.|  
  
## Comentários  
 Crie um objeto da classe `COlePasteSpecialDialog` quando você deseja chamar essa caixa de diálogo.  Depois que um objeto de `COlePasteSpecialDialog` foi construído, você pode usar as funções de membro de [AddFormat](../Topic/COlePasteSpecialDialog::AddFormat.md) e de [AddStandardFormats](../Topic/COlePasteSpecialDialog::AddStandardFormats.md) para adicionar formatos da área de transferência para a caixa de diálogo.  Você também pode usar a estrutura de [m\_ps](../Topic/COlePasteSpecialDialog::m_ps.md) para inicializar valores ou estados de controles na caixa de diálogo.  A estrutura de `m_ps` é do tipo **OLEUIPASTESPECIAL**.  
  
 Para obter mais informações, consulte a estrutura de [OLEUIPASTESPECIAL](http://msdn.microsoft.com/library/windows/desktop/ms692434) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações sobre caixas de diálogo OLE\- específicas, consulte o artigo [Caixas de diálogo no OLE](../../mfc/dialog-boxes-in-ole.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../Topic/CCommonDialog%20Class.md)  
  
 [COleDialog](../../mfc/reference/coledialog-class.md)  
  
 `COlePasteSpecialDialog`  
  
## Requisitos  
 **Cabeçalho:** afxodlgs.h  
  
## Consulte também  
 [Exemplo OCLIENT MFC](../../top/visual-cpp-samples.md)   
 [Classe de COleDialog](../../mfc/reference/coledialog-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de COleDialog](../../mfc/reference/coledialog-class.md)