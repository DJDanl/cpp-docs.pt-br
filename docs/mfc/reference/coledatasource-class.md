---
title: "Classe de COleDataSource | Microsoft Docs"
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
  - "COleDataSource"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Área de transferência [C++], Suporte MFC"
  - "Área de transferência [C++], Suporte OLE"
  - "Classe de COleDataSource"
  - "transferência de dados [C++], O OLE"
  - "arrastar e soltar [C++], Suporte MFC"
  - "IDataObject, Encapsulamento MFC"
  - "OLE [C++], transferência de dados uniforme"
  - "Área de transferência OLE [C++], suporte"
  - "Transferência de dados OLE [C++]"
  - "transferência de dados uniforme"
  - "transferência de dados uniforme, O OLE"
ms.assetid: 02c8ee7d-8e10-4463-8613-bb2a0305ca69
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleDataSource
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Atua como um cache em que um aplicativo coloca os dados que oferecerá durante operações de transferência de dados, como a área de transferência ou operações de arrastar e soltar.  
  
## Sintaxe  
  
```  
class COleDataSource : public CCmdTarget  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleDataSource::COleDataSource](../Topic/COleDataSource::COleDataSource.md)|Constrói um objeto de `COleDataSource` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleDataSource::CacheData](../Topic/COleDataSource::CacheData.md)|Oferece de dados em um formato especificado usando uma estrutura de **STGMEDIUM** .|  
|[COleDataSource::CacheGlobalData](../Topic/COleDataSource::CacheGlobalData.md)|Oferece dados em um formato especificado usando `HGLOBAL`.|  
|[COleDataSource::DelayRenderData](../Topic/COleDataSource::DelayRenderData.md)|Oferece dados em um formato especificado usando processar tarde.|  
|[COleDataSource::DelayRenderFileData](../Topic/COleDataSource::DelayRenderFileData.md)|Oferece dados em um formato especificado em um ponteiro de `CFile` .|  
|[COleDataSource::DelaySetData](../Topic/COleDataSource::DelaySetData.md)|Chamado para cada formato que é suportado em `OnSetData`.|  
|[COleDataSource::DoDragDrop](../Topic/COleDataSource::DoDragDrop.md)|Executar operações de arrastar\-e\-soltar com uma fonte de dados.|  
|[COleDataSource::Empty](../Topic/COleDataSource::Empty.md)|Limpa o objeto de `COleDataSource` de dados.|  
|[COleDataSource::FlushClipboard](../Topic/COleDataSource::FlushClipboard.md)|Processa os dados à área de transferência.|  
|[COleDataSource::GetClipboardOwner](../Topic/COleDataSource::GetClipboardOwner.md)|Verifica se os dados colocados na área de transferência são ainda existem.|  
|[COleDataSource::OnRenderData](../Topic/COleDataSource::OnRenderData.md)|Recupera dados como parte de renderização tarde.|  
|[COleDataSource::OnRenderFileData](../Topic/COleDataSource::OnRenderFileData.md)|Recupera dados em `CFile` como parte de renderização tarde.|  
|[COleDataSource::OnRenderGlobalData](../Topic/COleDataSource::OnRenderGlobalData.md)|Recupera dados em `HGLOBAL` como parte de renderização tarde.|  
|[COleDataSource::OnSetData](../Topic/COleDataSource::OnSetData.md)|Chamado para substituir os dados em `COleDataSource` objeto.|  
|[COleDataSource::SetClipboard](../Topic/COleDataSource::SetClipboard.md)|Coloca um objeto de `COleDataSource` na área de transferência.|  
  
## Comentários  
 Você pode criar fontes de dados VELHOS diretamente.  Como alternativa, classes de [COleClientItem](../../mfc/reference/coleclientitem-class.md) e de [COleServerItem](../../mfc/reference/coleserveritem-class.md) criar fontes de dados VELHOS em resposta às funções de membro de `CopyToClipboard` e de `DoDragDrop` .  Consulte [COleServerItem::CopyToClipboard](../Topic/COleServerItem::CopyToClipboard.md) para uma breve descrição.  Substitua a função de membro de `OnGetClipboardData` de sua classe de item de cliente ou item de servidor para adicionar formatos adicionais da área de transferência a dados na fonte de dados OLE criada para a função de membro de `CopyToClipboard` ou de `DoDragDrop` .  
  
 Sempre que você deseja preparar dados para uma transferência, você deve criar um objeto da classe e para preenchê\-lo com seus dados que usam ao máximo o método apropriado para seus dados.  A maneira que é inserido em uma fonte de dados é afetado diretamente pelo se os dados são fornecidos imediatamente \(processamento imediata\) ou sob demanda \(processar posteriores\).  Para cada formato da área de transferência em que você está fornecendo dados passando o formato da área de transferência a ser usado \(e uma estrutura de [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) opcional\), [DelayRenderData](../Topic/COleDataSource::DelayRenderData.md)chamada.  
  
 Para obter mais informações sobre fontes de dados e de transferência de dados, consulte o artigo [Objetos de dados e fontes de dados \(OLE\)](../../mfc/data-objects-and-data-sources-ole.md).  Além de isso, o artigo [Tópicos da área de transferência](../../mfc/clipboard.md) descreve o mecanismo OLE da área de transferência.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 `COleDataSource`  
  
## Requisitos  
 **Cabeçalho:** afxole.h  
  
## Consulte também  
 [Exemplo HIERSVR MFC](../../top/visual-cpp-samples.md)   
 [Exemplo OCLIENT MFC](../../top/visual-cpp-samples.md)   
 [Classe de CCmdTarget](../Topic/CCmdTarget%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de COleDataObject](../../mfc/reference/coledataobject-class.md)