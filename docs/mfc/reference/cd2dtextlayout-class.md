---
title: Classe CD2DTextLayout | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CD2DTextLayout
- AFXRENDERTARGET/CD2DTextLayout
- AFXRENDERTARGET/CD2DTextLayout::CD2DTextLayout
- AFXRENDERTARGET/CD2DTextLayout::Create
- AFXRENDERTARGET/CD2DTextLayout::Destroy
- AFXRENDERTARGET/CD2DTextLayout::Get
- AFXRENDERTARGET/CD2DTextLayout::GetFontFamilyName
- AFXRENDERTARGET/CD2DTextLayout::GetLocaleName
- AFXRENDERTARGET/CD2DTextLayout::IsValid
- AFXRENDERTARGET/CD2DTextLayout::ReCreate
- AFXRENDERTARGET/CD2DTextLayout::SetFontFamilyName
- AFXRENDERTARGET/CD2DTextLayout::SetLocaleName
- AFXRENDERTARGET/CD2DTextLayout::m_pTextLayout
dev_langs:
- C++
helpviewer_keywords:
- CD2DTextLayout class
ms.assetid: 724bd13c-f2ef-4e55-a775-8cb04b7b7908
caps.latest.revision: 16
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: b9d3873058613041042857b7edf213d207f058c5
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cd2dtextlayout-class"></a>Classe CD2DTextLayout
Um wrapper para IDWriteTextLayout.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DTextLayout : public CD2DResource;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DTextLayout::CD2DTextLayout](#cd2dtextlayout)|Constrói um objeto CD2DTextLayout.|  
|[CD2DTextLayout:: ~ CD2DTextLayout](#cd2dtextlayout__~cd2dtextlayout)|O destruidor. Chamado quando um objeto de layout de texto D2D está sendo destruído.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DTextLayout::Create](#create)|Cria um CD2DTextLayout. (Substitui [CD2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|  
|[CD2DTextLayout::Destroy](#destroy)|Destrói um objeto CD2DTextLayout. (Substitui [CD2DResource::Destroy](../../mfc/reference/cd2dresource-class.md#destroy).)|  
|[CD2DTextLayout::Get](#get)|Interface de IDWriteTextLayout retorna|  
|[CD2DTextLayout::GetFontFamilyName](#getfontfamilyname)|Copia o nome de família de fonte do texto na posição especificada.|  
|[CD2DTextLayout::GetLocaleName](#getlocalename)|Obtém o nome da localidade do texto na posição especificada.|  
|[CD2DTextLayout::IsValid](#isvalid)|Verifica a validade do recurso (substituições [CD2DResource::IsValid](../../mfc/reference/cd2dresource-class.md#isvalid).)|  
|[CD2DTextLayout::ReCreate](#recreate)|Cria um CD2DTextLayout novamente. (Substitui [CD2DResource::ReCreate](../../mfc/reference/cd2dresource-class.md#recreate).)|  
|[CD2DTextLayout::SetFontFamilyName](#setfontfamilyname)|Nome de família de fonte de terminação nula conjuntos para texto em um intervalo de texto especificado|  
|[CD2DTextLayout::SetLocaleName](#setlocalename)|Define o nome da localidade para o texto dentro de um intervalo de texto especificado|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DTextLayout::Operator IDWriteTextLayout *](#operator_idwritetextlayout_star)|Interface de IDWriteTextLayout retorna|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DTextLayout::m_pTextLayout](#m_ptextlayout)|Um ponteiro para um IDWriteTextLayout.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CD2DResource](../../mfc/reference/cd2dresource-class.md)  
  
 [CD2DTextLayout](../../mfc/reference/cd2dtextlayout-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="_dtorcd2dtextlayout"></a>CD2DTextLayout:: ~ CD2DTextLayout  
 O destruidor. Chamado quando um objeto de layout de texto D2D está sendo destruído.  
  
```  
virtual ~CD2DTextLayout();
```  
  
##  <a name="cd2dtextlayout"></a>CD2DTextLayout::CD2DTextLayout  
 Constrói um objeto CD2DTextLayout.  
  
```  
CD2DTextLayout(
    CRenderTarget* pParentTarget,  
    const CString& strText,  
    CD2DTextFormat& textFormat,  
    const CD2DSizeF& sizeMax,  
    BOOL bAutoDestroy = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParentTarget`  
 Um ponteiro para o destino de renderização.  
  
 `strText`  
 Um objeto CString que contém a cadeia de caracteres para criar um novo objeto CD2DTextLayout de.  
  
 `textFormat`  
 Um objeto CString que contém o formato a ser aplicado à cadeia de caracteres.  
  
 `sizeMax`  
 O tamanho da caixa de layout.  
  
 `bAutoDestroy`  
 Indica que o objeto será destruído pelo proprietário (pParentTarget).  
  
##  <a name="create"></a>CD2DTextLayout::Create  
 Cria um CD2DTextLayout.  
  
```  
virtual HRESULT Create(CRenderTarget* */);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.  
  
##  <a name="destroy"></a>CD2DTextLayout::Destroy  
 Destrói um objeto CD2DTextLayout.  
  
```  
virtual void Destroy();
```  
  
##  <a name="get"></a>CD2DTextLayout::Get  
 Interface de IDWriteTextLayout retorna  
  
```  
IDWriteTextLayout* Get();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface IDWriteTextLayout ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="getfontfamilyname"></a>CD2DTextLayout::GetFontFamilyName  
 Copia o nome de família de fonte do texto na posição especificada.  
  
```  
CString GetFontFamilyName(
    UINT32 currentPosition,  
    DWRITE_TEXT_RANGE* textRange = NULL) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `currentPosition`  
 A posição do texto para examinar.  
  
 `textRange`  
 O intervalo de texto com a mesma formatação como texto na posição especificada por currentPosition. Isso significa que a execução tem a formatação exata como a posição especificada, incluindo mas não limitado para o nome de família de fonte.  
  
### <a name="return-value"></a>Valor de retorno  
 Objeto CString que contém o nome de família de fonte atual.  
  
##  <a name="getlocalename"></a>CD2DTextLayout::GetLocaleName  
 Obtém o nome da localidade do texto na posição especificada.  
  
```  
CString GetLocaleName(
    UINT32 currentPosition,  
    DWRITE_TEXT_RANGE* textRange = NULL) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `currentPosition`  
 A posição do texto a ser inspecionado.  
  
 `textRange`  
 O intervalo de texto com a mesma formatação como texto na posição especificada por currentPosition. Isso significa que a execução tem a formatação exata como a posição especificada, incluindo mas não limitado para o nome da localidade.  
  
### <a name="return-value"></a>Valor de retorno  
 Objeto CString que contém o nome da localidade atual.  
  
##  <a name="isvalid"></a>CD2DTextLayout::IsValid  
 Verificações de validade de recursos  
  
```  
virtual BOOL IsValid() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o recurso é válido. Caso contrário, FALSE.  
  
##  <a name="m_ptextlayout"></a>CD2DTextLayout::m_pTextLayout  
 Um ponteiro para um IDWriteTextLayout.  
  
```  
IDWriteTextLayout* m_pTextLayout;  
```  
  
##  <a name="operator_idwritetextlayout_star"></a>CD2DTextLayout::Operator IDWriteTextLayout *  
 Interface de IDWriteTextLayout retorna  
  
```  
operator IDWriteTextLayout*();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface IDWriteTextLayout ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="recreate"></a>CD2DTextLayout::ReCreate  
 Cria um CD2DTextLayout novamente.  
  
```  
virtual HRESULT ReCreate(CRenderTarget* */);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.  
  
##  <a name="setfontfamilyname"></a>CD2DTextLayout::SetFontFamilyName  
 Nome de família de fonte de terminação nula conjuntos para texto em um intervalo de texto especificado  
  
```  
BOOL SetFontFamilyName(
    LPCWSTR pwzFontFamilyName,  
    DWRITE_TEXT_RANGE textRange);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pwzFontFamilyName`  
 O nome de família de fonte que se aplica à sequência de texto todo dentro do intervalo especificado por textRange  
  
 `textRange`  
 Intervalo de texto para que essa alteração se aplica  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará TRUE. Caso contrário, retornará FALSE  
  
##  <a name="setlocalename"></a>CD2DTextLayout::SetLocaleName  
 Define o nome da localidade para o texto dentro de um intervalo de texto especificado  
  
```  
BOOL SetLocaleName(
    LPCWSTR pwzLocaleName,  
    DWRITE_TEXT_RANGE textRange);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pwzLocaleName`  
 Uma cadeia de caracteres de nome de localidade terminada em nulo  
  
 `textRange`  
 Intervalo de texto para que essa alteração se aplica  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará TRUE. Caso contrário, retornará FALSE  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

