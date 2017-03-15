---
title: Classe CHtmlEditDoc | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CHtmlEditDoc
dev_langs:
- C++
helpviewer_keywords:
- CHtmlEditDoc class
ms.assetid: b2cca61f-e5d6-4099-b0d1-46bf85f0bd64
caps.latest.revision: 24
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 1d9651c5009fd8f4c742c6b9bf08e32bd67c7d30
ms.lasthandoff: 02/25/2017

---
# <a name="chtmleditdoc-class"></a>Classe CHtmlEditDoc
Com [CHtmlEditView](../../mfc/reference/chtmleditview-class.md), fornece a funcionalidade da plataforma WebBrowser edição dentro do contexto da arquitetura de exibição de documento do MFC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class AFX_NOVTABLE CHtmlEditDoc : public CDocument  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHtmlEditDoc::CHtmlEditDoc](#chtmleditdoc)|Constrói um objeto `CHtmlEditDoc`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHtmlEditDoc::GetView](#getview)|Recupera o `CHtmlEditView` objeto anexado a este documento.|  
|[CHtmlEditDoc::IsModified](#ismodified)|Retorna se o controle WebBrowser de associado do modo de exibição contém um documento que tenha sido modificado pelo usuário.|  
|[CHtmlEditDoc::OpenURL](#openurl)|Abre uma URL.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CDocument](../../mfc/reference/cdocument-class.md)  
  
 `CHtmlEditDoc`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxhtml.h  
  
##  <a name="a-namechtmleditdoca--chtmleditdocchtmleditdoc"></a><a name="chtmleditdoc"></a>CHtmlEditDoc::CHtmlEditDoc  
 Constrói uma **CHtmlEditDoc** objeto.  
  
```  
CHtmlEditDoc();
```  
  
##  <a name="a-namegetviewa--chtmleditdocgetview"></a><a name="getview"></a>CHtmlEditDoc::GetView  
 Recupera o [CHtmlEditView](../../mfc/reference/chtmleditview-class.md) objeto anexado a este documento.  
  
```  
virtual CHtmlEditView* GetView() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o documento **CHtmlEditView** objeto.  
  
##  <a name="a-nameismodifieda--chtmleditdocismodified"></a><a name="ismodified"></a>CHtmlEditDoc::IsModified  
 Retorna se o controle WebBrowser de associado do modo de exibição contém um documento que tenha sido modificado pelo usuário.  
  
```  
virtual BOOL IsModified();
```  
  
##  <a name="a-nameopenurla--chtmleditdocopenurl"></a><a name="openurl"></a>CHtmlEditDoc::OpenURL  
 Abre uma URL.  
  
```  
virtual BOOL OpenURL(LPCTSTR lpszURL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszURL`  
 A URL para abrir.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** com êxito, **FALSE** em caso de falha.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de HTMLEdit](../../visual-cpp-samples.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)


