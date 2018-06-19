---
title: Classe CHtmlEditDoc | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CHtmlEditDoc
- AFXHTML/CHtmlEditDoc
- AFXHTML/CHtmlEditDoc::CHtmlEditDoc
- AFXHTML/CHtmlEditDoc::GetView
- AFXHTML/CHtmlEditDoc::IsModified
- AFXHTML/CHtmlEditDoc::OpenURL
dev_langs:
- C++
helpviewer_keywords:
- CHtmlEditDoc [MFC], CHtmlEditDoc
- CHtmlEditDoc [MFC], GetView
- CHtmlEditDoc [MFC], IsModified
- CHtmlEditDoc [MFC], OpenURL
ms.assetid: b2cca61f-e5d6-4099-b0d1-46bf85f0bd64
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: de452365a02b69798c62e2eecfd8051afcf08bb8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33366965"
---
# <a name="chtmleditdoc-class"></a>Classe CHtmlEditDoc
Com [CHtmlEditView](../../mfc/reference/chtmleditview-class.md), fornece a funcionalidade da plataforma de edição de WebBrowser dentro do contexto da arquitetura do modo de exibição de documentos do MFC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class AFX_NOVTABLE CHtmlEditDoc : public CDocument  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHtmlEditDoc::CHtmlEditDoc](#chtmleditdoc)|Constrói um objeto `CHtmlEditDoc`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHtmlEditDoc::GetView](#getview)|Recupera o `CHtmlEditView` objeto anexado a este documento.|  
|[CHtmlEditDoc::IsModified](#ismodified)|Retorna se o controle WebBrowser de associados do modo de exibição contém um documento que foi modificado pelo usuário.|  
|[CHtmlEditDoc::OpenURL](#openurl)|Abre uma URL.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CDocument](../../mfc/reference/cdocument-class.md)  
  
 `CHtmlEditDoc`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxhtml.h  
  
##  <a name="chtmleditdoc"></a>  CHtmlEditDoc::CHtmlEditDoc  
 Constrói um **CHtmlEditDoc** objeto.  
  
```  
CHtmlEditDoc();
```  
  
##  <a name="getview"></a>  CHtmlEditDoc::GetView  
 Recupera o [CHtmlEditView](../../mfc/reference/chtmleditview-class.md) objeto anexado a este documento.  
  
```  
virtual CHtmlEditView* GetView() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o documento **CHtmlEditView** objeto.  
  
##  <a name="ismodified"></a>  CHtmlEditDoc::IsModified  
 Retorna se o controle WebBrowser de associados do modo de exibição contém um documento que foi modificado pelo usuário.  
  
```  
virtual BOOL IsModified();
```  
  
##  <a name="openurl"></a>  CHtmlEditDoc::OpenURL  
 Abre uma URL.  
  
```  
virtual BOOL OpenURL(LPCTSTR lpszURL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszURL`  
 A URL para abrir.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** em caso de sucesso, **FALSE** em caso de falha.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de HTMLEdit](../../visual-cpp-samples.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

