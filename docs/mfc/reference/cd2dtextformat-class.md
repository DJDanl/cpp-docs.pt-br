---
title: Classe CD2DTextFormat | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CD2DTextFormat
- AFXRENDERTARGET/CD2DTextFormat
- AFXRENDERTARGET/CD2DTextFormat::CD2DTextFormat
- AFXRENDERTARGET/CD2DTextFormat::Create
- AFXRENDERTARGET/CD2DTextFormat::Destroy
- AFXRENDERTARGET/CD2DTextFormat::Get
- AFXRENDERTARGET/CD2DTextFormat::GetFontFamilyName
- AFXRENDERTARGET/CD2DTextFormat::GetLocaleName
- AFXRENDERTARGET/CD2DTextFormat::IsValid
- AFXRENDERTARGET/CD2DTextFormat::ReCreate
- AFXRENDERTARGET/CD2DTextFormat::m_pTextFormat
dev_langs:
- C++
helpviewer_keywords:
- CD2DTextFormat [MFC], CD2DTextFormat
- CD2DTextFormat [MFC], Create
- CD2DTextFormat [MFC], Destroy
- CD2DTextFormat [MFC], Get
- CD2DTextFormat [MFC], GetFontFamilyName
- CD2DTextFormat [MFC], GetLocaleName
- CD2DTextFormat [MFC], IsValid
- CD2DTextFormat [MFC], ReCreate
- CD2DTextFormat [MFC], m_pTextFormat
ms.assetid: db194cec-9dae-4644-ab84-7c43b7164117
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 26fbbbe2d9f5edde6e247d69e9e6bc840f05a55b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cd2dtextformat-class"></a>Classe CD2DTextFormat
Um wrapper para IDWriteTextFormat.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DTextFormat : public CD2DResource;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DTextFormat::CD2DTextFormat](#cd2dtextformat)|Constrói um objeto CD2DTextFormat.|  
|[CD2DTextFormat:: ~ CD2DTextFormat](#cd2dtextformat__~cd2dtextformat)|O destruidor. Chamado quando um objeto no formato texto D2D está sendo destruído.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DTextFormat::Create](#create)|Cria um CD2DTextFormat. (Substitui [CD2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|  
|[CD2DTextFormat::Destroy](#destroy)|Destrói um objeto CD2DTextFormat. (Substitui [CD2DResource::Destroy](../../mfc/reference/cd2dresource-class.md#destroy).)|  
|[CD2DTextFormat::Get](#get)|Interface de IDWriteTextFormat retorna|  
|[CD2DTextFormat::GetFontFamilyName](#getfontfamilyname)|Obtém uma cópia do nome de família da fonte.|  
|[CD2DTextFormat::GetLocaleName](#getlocalename)|Obtém uma cópia do nome da localidade.|  
|[CD2DTextFormat::IsValid](#isvalid)|Verifica a validade do recurso (substitui [CD2DResource::IsValid](../../mfc/reference/cd2dresource-class.md#isvalid).)|  
|[CD2DTextFormat::ReCreate](#recreate)|Recria um CD2DTextFormat. (Substitui [CD2DResource::ReCreate](../../mfc/reference/cd2dresource-class.md#recreate).)|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DTextFormat::Operator IDWriteTextFormat *](#operator_idwritetextformat_star)|Interface de IDWriteTextFormat retorna|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DTextFormat::m_pTextFormat](#m_ptextformat)|Um ponteiro para um IDWriteTextFormat.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CD2DResource](../../mfc/reference/cd2dresource-class.md)  
  
 [CD2DTextFormat](../../mfc/reference/cd2dtextformat-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="_dtorcd2dtextformat"></a>CD2DTextFormat:: ~ CD2DTextFormat  
 O destruidor. Chamado quando um objeto no formato texto D2D está sendo destruído.  
  
```  
virtual ~CD2DTextFormat();
```  
  
##  <a name="cd2dtextformat"></a>CD2DTextFormat::CD2DTextFormat  
 Constrói um objeto CD2DTextFormat.  
  
```  
CD2DTextFormat(
    CRenderTarget* pParentTarget,  
    const CString& strFontFamilyName,  
    FLOAT fontSize,  
    DWRITE_FONT_WEIGHT fontWeight = DWRITE_FONT_WEIGHT_NORMAL,  
    DWRITE_FONT_STYLE fontStyle = DWRITE_FONT_STYLE_NORMAL,  
    DWRITE_FONT_STRETCH fontStretch = DWRITE_FONT_STRETCH_NORMAL,  
    const CString& strFontLocale = _T(""),  
    IDWriteFontCollection* pFontCollection = NULL,  
    BOOL bAutoDestroy = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParentTarget`  
 Um ponteiro para o destino de renderização.  
  
 `strFontFamilyName`  
 Um objeto de CString que contém o nome da família de fonte.  
  
 `fontSize`  
 O tamanho lógico da fonte em unidades DIP ("pixel independente de dispositivo"). Um DIPequals 1/96 polegada.  
  
 `fontWeight`  
 Um valor que indica a espessura da fonte para o objeto de texto.  
  
 `fontStyle`  
 Um valor que indica o estilo da fonte para o objeto de texto.  
  
 `fontStretch`  
 Um valor que indica a ampliação de fonte para o objeto de texto.  
  
 `strFontLocale`  
 Um objeto de CString que contém o nome da localidade.  
  
 `pFontCollection`  
 Um ponteiro para um objeto de coleção de fontes. Quando isso for NULL, indica a coleção de fontes de sistema.  
  
 `bAutoDestroy`  
 Indica se o objeto será destruído pelo proprietário (pParentTarget).  
  
##  <a name="create"></a>CD2DTextFormat::Create  
 Cria um CD2DTextFormat.  
  
```  
virtual HRESULT Create(CRenderTarget* */);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.  
  
##  <a name="destroy"></a>CD2DTextFormat::Destroy  
 Destrói um objeto CD2DTextFormat.  
  
```  
virtual void Destroy();
```  
  
##  <a name="get"></a>CD2DTextFormat::Get  
 Interface de IDWriteTextFormat retorna  
  
```  
IDWriteTextFormat* Get();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface IDWriteTextFormat ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="getfontfamilyname"></a>CD2DTextFormat::GetFontFamilyName  
 Obtém uma cópia do nome de família da fonte.  
  
```  
CString GetFontFamilyName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Objeto de CString que contém o nome de família de fonte atual.  
  
##  <a name="getlocalename"></a>CD2DTextFormat::GetLocaleName  
 Obtém uma cópia do nome da localidade.  
  
```  
CString GetLocaleName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Objeto de CString que contém o nome da localidade atual.  
  
##  <a name="isvalid"></a>CD2DTextFormat::IsValid  
 Verificações de validade de recurso  
  
```  
virtual BOOL IsValid() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o recurso é válido. Caso contrário, FALSE.  
  
##  <a name="m_ptextformat"></a>CD2DTextFormat::m_pTextFormat  
 Um ponteiro para um IDWriteTextFormat.  
  
```  
IDWriteTextFormat* m_pTextFormat;  
```  
  
##  <a name="operator_idwritetextformat_star"></a>CD2DTextFormat::Operator IDWriteTextFormat *  
 Interface de IDWriteTextFormat retorna  
  
```  
operator IDWriteTextFormat*();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface IDWriteTextFormat ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="recreate"></a>CD2DTextFormat::ReCreate  
 Recria um CD2DTextFormat.  
  
```  
virtual HRESULT ReCreate(CRenderTarget* */);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
