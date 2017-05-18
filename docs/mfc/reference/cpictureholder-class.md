---
title: Classe CPictureHolder | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CPictureHolder
- AFXCTL/CPictureHolder
- AFXCTL/CPictureHolder::CPictureHolder
- AFXCTL/CPictureHolder::CreateEmpty
- AFXCTL/CPictureHolder::CreateFromBitmap
- AFXCTL/CPictureHolder::CreateFromIcon
- AFXCTL/CPictureHolder::CreateFromMetafile
- AFXCTL/CPictureHolder::GetDisplayString
- AFXCTL/CPictureHolder::GetPictureDispatch
- AFXCTL/CPictureHolder::GetType
- AFXCTL/CPictureHolder::Render
- AFXCTL/CPictureHolder::SetPictureDispatch
- AFXCTL/CPictureHolder::m_pPict
dev_langs:
- C++
helpviewer_keywords:
- Picture property
- controls [MFC], OLE
- OLE controls, image
- CPictureHolder class
ms.assetid: a4f59775-704a-41dd-b5bd-2e531c95127a
caps.latest.revision: 20
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 14a774e3edc8b5e160b287612d3709c3424503be
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cpictureholder-class"></a>Classe CPictureHolder
Implementa uma propriedade de imagem, que permite ao usuário exibir uma imagem em seu controle.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CPictureHolder  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPictureHolder::CPictureHolder](#cpictureholder)|Constrói um objeto `CPictureHolder`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPictureHolder::CreateEmpty](#createempty)|Cria um vazio `CPictureHolder` objeto.|  
|[CPictureHolder::CreateFromBitmap](#createfrombitmap)|Cria um `CPictureHolder` objeto a partir de um bitmap.|  
|[CPictureHolder::CreateFromIcon](#createfromicon)|Cria um `CPictureHolder` objeto a partir de um ícone.|  
|[CPictureHolder::CreateFromMetafile](#createfrommetafile)|Cria um `CPictureHolder` objeto a partir de um metarquivo.|  
|[CPictureHolder::GetDisplayString](#getdisplaystring)|Recupera a cadeia de caracteres exibida no navegador de propriedade de um controle do contêiner.|  
|[CPictureHolder::GetPictureDispatch](#getpicturedispatch)|Retorna o `CPictureHolder` do objeto `IDispatch` interface.|  
|[CPictureHolder::GetType](#gettype)|Informa se o `CPictureHolder` objeto é um bitmap, um metarquivo ou um ícone.|  
|[CPictureHolder::Render](#render)|Processa a imagem.|  
|[CPictureHolder::SetPictureDispatch](#setpicturedispatch)|Conjuntos de `CPictureHolder` do objeto `IDispatch` interface.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPictureHolder::m_pPict](#m_ppict)|Um ponteiro para um objeto de imagem.|  
  
## <a name="remarks"></a>Comentários  
 `CPictureHolder`não tem uma classe base.  
  
 Com a propriedade de imagem de estoque, o desenvolvedor pode especificar um bitmap, ícone ou meta-arquivo para exibição.  
  
 Para obter informações sobre como criar propriedades de imagem personalizada, consulte o artigo [controles ActiveX MFC: usando imagens em um controle ActiveX](../../mfc/mfc-activex-controls-using-pictures-in-an-activex-control.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CPictureHolder`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxctl.h  
  
##  <a name="cpictureholder"></a>CPictureHolder::CPictureHolder  
 Constrói um objeto `CPictureHolder`.  
  
```  
CPictureHolder();
```  
  
##  <a name="createempty"></a>CPictureHolder::CreateEmpty  
 Cria um vazio `CPictureHolder` de objeto e se conecta a um `IPicture` interface.  
  
```  
BOOL CreateEmpty();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o objeto é criado com êxito; Caso contrário, 0.  
  
##  <a name="createfrombitmap"></a>CPictureHolder::CreateFromBitmap  
 Usa um bitmap para inicializar o objeto de imagem em um `CPictureHolder`.  
  
```  
BOOL CreateFromBitmap(
    UINT idResource);

 
BOOL CreateFromBitmap(
    CBitmap* pBitmap,  
    CPalette* pPal = NULL,  
    BOOL bTransferOwnership = TRUE);

 
BOOL CreateFromBitmap(
    HBITMAP hbm,  
    HPALETTE hpal = NULL,  
    BOOL bTransferOwnership = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `idResource`  
 ID de recurso de um recurso de bitmap.  
  
 `pBitmap`  
 Ponteiro para uma [CBitmap](../../mfc/reference/cbitmap-class.md) objeto.  
  
 *pPal*  
 Ponteiro para uma [CPalette](../../mfc/reference/cpalette-class.md) objeto.  
  
 `bTransferOwnership`  
 Indica se o objeto de imagem será assumir a propriedade dos objetos de bitmap e paleta.  
  
 `hbm`  
 Identificador para o bitmap do qual o `CPictureHolder` objeto é criado.  
  
 `hpal`  
 Identificador para a paleta usada para renderizar o bitmap.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o objeto é criado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se `bTransferOwnership` é **TRUE**, o chamador não deve usar o bitmap ou retorna um objeto da paleta de alguma forma após esta chamada. Se `bTransferOwnership` é **FALSE**, o chamador é responsável por garantir que os objetos de bitmap e paleta permanecem válidos para o tempo de vida do objeto de imagem.  
  
##  <a name="createfromicon"></a>CPictureHolder::CreateFromIcon  
 Usa um ícone para inicializar o objeto de imagem em um `CPictureHolder`.  
  
```  
BOOL CreateFromIcon(
    UINT idResource);

 
BOOL CreateFromIcon(
    HICON hIcon,  
    BOOL bTransferOwnership = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `idResource`  
 ID de recurso de um recurso de bitmap.  
  
 `hIcon`  
 Identificador para o ícone do qual o `CPictureHolder` objeto é criado.  
  
 `bTransferOwnership`  
 Indica se o objeto de imagem será assumir a propriedade do objeto de ícone.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o objeto é criado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se `bTransferOwnership` é **TRUE**, o chamador não deve usar o objeto do ícone de alguma forma depois retorna essa chamada. Se `bTransferOwnership` é **FALSE**, o chamador é responsável por garantir que o objeto de ícone permanece válido para o tempo de vida do objeto de imagem.  
  
##  <a name="createfrommetafile"></a>CPictureHolder::CreateFromMetafile  
 Usa um metarquivo para inicializar o objeto de imagem em um `CPictureHolder`.  
  
```  
BOOL CreateFromMetafile(
    HMETAFILE hmf,  
    int xExt,  
    int yExt,  
    BOOL bTransferOwnership = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hmf`  
 Identificador para o metarquivo usado para criar o `CPictureHolder` objeto.  
  
 *xExt*  
 X extensão da imagem.  
  
 *yExt*  
 Extensão de Y da imagem.  
  
 `bTransferOwnership`  
 Indica se o objeto de imagem será assumir a propriedade do objeto metarquivo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o objeto é criado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se `bTransferOwnership` é **TRUE**, o chamador não deve usar o objeto de metarquivo de alguma forma depois retorna essa chamada. Se `bTransferOwnership` é **FALSE**, o chamador é responsável por garantir que o objeto de metarquivo permanece válido para o tempo de vida do objeto de imagem.  
  
##  <a name="getdisplaystring"></a>CPictureHolder::GetDisplayString  
 Recupera a cadeia de caracteres que é exibida no navegador de propriedade do contêiner.  
  
```  
BOOL GetDisplayString(CString& strValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `strValue`  
 Referência para o [CString](../../atl-mfc-shared/reference/cstringt-class.md) que é armazenar a cadeia de exibição.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a cadeia de caracteres é recuperada com êxito. Caso contrário, 0.  
  
##  <a name="getpicturedispatch"></a>CPictureHolder::GetPictureDispatch  
 Esta função retorna um ponteiro para o `CPictureHolder` do objeto `IPictureDisp` interface.  
  
```  
LPPICTUREDISP GetPictureDispatch();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `CPictureHolder` do objeto `IPictureDisp` interface.  
  
### <a name="remarks"></a>Comentários  
 O chamador deve chamar **versão** esse ponteiro quando terminar com ele.  
  
##  <a name="gettype"></a>CPictureHolder::GetType  
 Indica se a imagem é um bitmap, ícone ou metarquivo.  
  
```  
short GetType();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que indica o tipo da imagem. Os valores possíveis e seus significados são os seguintes:  
  
|Valor|Significado|  
|-----------|-------------|  
|**PICTYPE_UNINITIALIZED**|`CPictureHolder`objeto é unititialized.|  
|**PICTYPE_NONE**|`CPictureHolder`objeto está vazio.|  
|**PICTYPE_BITMAP**|Imagem é um bitmap.|  
|**PICTYPE_METAFILE**|A figura é um metarquivo.|  
|**PICTYPE_ICON**|Figura é um ícone.|  
  
##  <a name="m_ppict"></a>CPictureHolder::m_pPict  
 Um ponteiro para o `CPictureHolder` do objeto `IPicture` interface.  
  
```  
LPPICTURE m_pPict;  
```  
  
##  <a name="render"></a>CPictureHolder::Render  
 Processa a imagem no retângulo referenciado pelo `rcRender`.  
  
```  
void Render(
    CDC* pDC,  
    const CRect& rcRender,  
    const CRect& rcWBounds);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Ponteiro para o contexto de exibição em que a imagem for processado.  
  
 `rcRender`  
 Retângulo na qual a imagem for processado.  
  
 *rcWBounds*  
 Um retângulo que representa o retângulo delimitador do objeto de renderização de imagem. Para um controle, esse retângulo é o `rcBounds` parâmetro passado para uma substituição de [COleControl::OnDraw](../../mfc/reference/colecontrol-class.md#ondraw).  
  
##  <a name="setpicturedispatch"></a>CPictureHolder::SetPictureDispatch  
 Conecta-se a `CPictureHolder` o objeto para um `IPictureDisp` interface.  
  
```  
void SetPictureDispatch(LPPICTUREDISP pDisp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDisp`  
 Ponteiro para o novo `IPictureDisp` interface.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CFontHolder](../../mfc/reference/cfontholder-class.md)

