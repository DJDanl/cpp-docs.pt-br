---
title: "Classe de COleDataObject | Microsoft Docs"
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
  - "IDataObject"
  - "COleDataObject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Área de transferência [C++], Suporte MFC"
  - "Área de transferência [C++], Suporte OLE"
  - "Classe de COleDataObject"
  - "transferência de dados [C++]"
  - "transferência de dados [C++], O OLE"
  - "arrastar e soltar [C++], Suporte MFC"
  - "Interface de IDataObject, Encapsulamento MFC"
  - "OLE [C++], transferência de dados uniforme"
  - "Área de transferência OLE [C++], suporte"
  - "Transferência de dados OLE [C++]"
  - "transferência de dados uniforme"
  - "transferência de dados uniforme, O OLE"
ms.assetid: d1cc84be-2e1c-4bb3-a8a0-565eb08aaa34
caps.latest.revision: 20
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleDataObject
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado nas transferências de dados para recuperar dados em vários formatos da área de transferência, com o arrastar e soltar a, ou um item OLE inserido.  
  
## Sintaxe  
  
```  
class COleDataObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleDataObject::COleDataObject](../Topic/COleDataObject::COleDataObject.md)|Constrói um objeto de `COleDataObject` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleDataObject::Attach](../Topic/COleDataObject::Attach.md)|Anexa o objeto de dados OLE especificado a `COleDataObject`.|  
|[COleDataObject::AttachClipboard](../Topic/COleDataObject::AttachClipboard.md)|Anexa o objeto de dados que está na área de transferência.|  
|[COleDataObject::BeginEnumFormats](../Topic/COleDataObject::BeginEnumFormats.md)|Prepara\-se para um ou mais chamadas subseqüentes de `GetNextFormat` .|  
|[COleDataObject::Detach](../Topic/COleDataObject::Detach.md)|Dispara o objeto associado de `IDataObject` .|  
|[COleDataObject::GetData](../Topic/COleDataObject::GetData.md)|Copia dados de objeto de dados OLE anexado em um formato especificado.|  
|[COleDataObject::GetFileData](../Topic/COleDataObject::GetFileData.md)|Copia dados de objeto de dados OLE anexado em um ponteiro de `CFile` no formato especificado.|  
|[COleDataObject::GetGlobalData](../Topic/COleDataObject::GetGlobalData.md)|Copia dados de objeto de dados OLE anexado em `HGLOBAL` no formato especificado.|  
|[COleDataObject::GetNextFormat](../Topic/COleDataObject::GetNextFormat.md)|Retorna o formato de dados seguir disponível.|  
|[COleDataObject::IsDataAvailable](../Topic/COleDataObject::IsDataAvailable.md)|Verifica se os dados estão disponíveis em um formato especificado.|  
|[COleDataObject::Release](../Topic/COleDataObject::Release.md)|Dispara e libera o objeto associado de `IDataObject` .|  
  
## Comentários  
 `COleDataObject` não tem uma classe base.  
  
 Esses tipos das transferências de dados incluem uma fonte e um destino.  A fonte de dados é implementada como um objeto da classe de [COleDataSource](../../mfc/reference/coledatasource-class.md) .  Sempre que um aplicativo alvo tem os dados ignorados ou ela for solicitado para executar uma operação da pasta da área de transferência, um objeto da classe de `COleDataObject` deve ser criado.  
  
 Esta classe permite que você determine se os dados existem em um formato especificado.  Você também pode enumerar os formatos de dados disponíveis ou para verificar se um formato determinado está disponível e então recuperar os dados no formato preferido.  A recuperação do objeto pode ser realizada em várias maneiras diferentes, incluindo o uso de [CFile](../../mfc/reference/cfile-class.md), `HGLOBAL`, ou uma estrutura de **STGMEDIUM** .  
  
 Para obter mais informações, consulte a estrutura de [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações sobre como usar objetos de dados em seu aplicativo, consulte o artigo [Objetos de dados e fontes de dados \(OLE\)](../../mfc/data-objects-and-data-sources-ole.md).  
  
## Hierarquia de herança  
 `COleDataObject`  
  
## Requisitos  
 **Cabeçalho:** afxole.h  
  
## Consulte também  
 [O MFC exemplos HIERSVR](../../top/visual-cpp-samples.md)   
 [Exemplo OCLIENT MFC](../../top/visual-cpp-samples.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de COleDataSource](../../mfc/reference/coledatasource-class.md)   
 [Classe de COleClientItem](../../mfc/reference/coleclientitem-class.md)   
 [Classe de COleServerItem](../../mfc/reference/coleserveritem-class.md)   
 [COleDataSource::DoDragDrop](../Topic/COleDataSource::DoDragDrop.md)   
 [CView::OnDrop](../Topic/CView::OnDrop.md)