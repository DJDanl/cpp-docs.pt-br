---
title: Classe CMFCToolBarImages | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCToolBarImages
dev_langs:
- C++
helpviewer_keywords:
- CMFCToolBarImages class
ms.assetid: d4e50518-9ffc-406f-9996-f79e5cd38155
caps.latest.revision: 31
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
ms.openlocfilehash: ff94497108033b17d52b79594fdbe30e8ed7da03
ms.lasthandoff: 02/25/2017

---
# <a name="cmfctoolbarimages-class"></a>Classe CMFCToolBarImages
As imagens em uma barra de ferramentas. O `CMFCToolBarImages` classe gerencia imagens de barra de ferramentas carregadas de recursos do aplicativo ou de arquivos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCToolBarImages : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBarImages::CMFCToolBarImages](#cmfctoolbarimages)|Constrói um objeto `CMFCToolBarImages`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBarImages::AdaptColors](#adaptcolors)||  
|[CMFCToolBarImages::AddIcon](#addicon)|Adiciona um ícone para as imagens da barra de ferramentas.|  
|[CMFCToolBarImages::AddImage](#addimage)|Adiciona um bitmap para as imagens da barra de ferramentas.|  
|[CMFCToolBarImages::CleanUp](#cleanup)||  
|[CMFCToolBarImages::Clear](#clear)|Libera os recursos do sistema que foram alocados para este objeto.|  
|[CMFCToolBarImages::ConvertTo32Bits](#convertto32bits)|Converte sublinhado bitmaps 32 bpp imagens.|  
|[CMFCToolBarImages::CopyImageToClipboard](#copyimagetoclipboard)||  
|[CMFCToolBarImages::CopyTo](#copyto)||  
|[CMFCToolBarImages::CreateFromImageList](#createfromimagelist)|Inicializa as imagens da barra de ferramentas de uma lista de imagens ( [classe CImageList](../../mfc/reference/cimagelist-class.md)).|  
|[CMFCToolBarImages::CreateRegionFromImage](#createregionfromimage)||  
|[CMFCToolBarImages::DeleteImage](#deleteimage)|Exclui a imagem que tem um índice especificado entre as imagens da barra de ferramentas se este conjunto de imagens da barra de ferramentas contém imagens definidas pelo usuário.|  
|[CMFCToolBarImages::Draw](#draw)|Desenha uma imagem única barra de ferramentas (botão).|  
|[CMFCToolBarImages::DrawEx](#drawex)||  
|[CMFCToolBarImages::EnableRTL](#enablertl)||  
|[CMFCToolBarImages::EndDrawImage](#enddrawimage)|Libera recursos do sistema após uma barra de ferramentas imagem é desenhada.|  
|[CMFCToolBarImages::ExtractIcon](#extracticon)|Retorna o ícone que tem um índice de imagem especificado entre as imagens da barra de ferramentas.|  
|[CMFCToolBarImages::FillDitheredRect](#fillditheredrect)|Preenche um retângulo usando um pincel com as cores de plano de fundo da barra de ferramentas.|  
|[CMFCToolBarImages::GetAlwaysLight](#getalwayslight)||  
|[CMFCToolBarImages::GetBitsPerPixel](#getbitsperpixel)|Retorna a resolução atual de imagens de sublinhado.|  
|[CMFCToolBarImages::GetCount](#getcount)|Retorna o número de imagens na barra de ferramentas.|  
|[CMFCToolBarImages::GetDisabledImageAlpha](#getdisabledimagealpha)|Retorna o valor de canal alfa é usado para imagens desabilitadas.|  
|[CMFCToolBarImages::GetFadedImageAlpha](#getfadedimagealpha)||  
|[CMFCToolBarImages::GetImageSize](#getimagesize)|Recupera o tamanho das imagens da barra de ferramentas que são armazenados na memória (tamanho da fonte) ou o tamanho das imagens da barra de ferramentas que são desenhadas na tela (tamanho de destino).|  
|[CMFCToolBarImages::GetImageWell](#getimagewell)|Retorna o identificador para o bitmap que contém todas as imagens da barra de ferramentas.|  
|[CMFCToolBarImages::GetImageWellLight](#getimagewelllight)||  
|[CMFCToolBarImages::GetLastImageRect](#getlastimagerect)||  
|[CMFCToolBarImages::GetLightPercentage](#getlightpercentage)||  
|[CMFCToolBarImages::GetMapTo3DColors](#getmapto3dcolors)||  
|[CMFCToolBarImages::GetMask](#getmask)||  
|[CMFCToolBarImages::GetResourceOffset](#getresourceoffset)|Retorna o índice de imagem para uma ID de recurso especificado.|  
|[CMFCToolBarImages::GetScale](#getscale)|Retorna a proporção de escala atual das imagens de sublinhado.|  
|[CMFCToolBarImages::GetTransparentColor](#gettransparentcolor)||  
|[CMFCToolBarImages::GrayImages](#grayimages)|Grays as imagens da barra de ferramentas para torná-las desabilitado.|  
|[CMFCToolBarImages::Is32BitTransparencySupported](#is32bittransparencysupported)|Determina se o sistema operacional oferece suporte a combinação alfa de 32 bits.|  
|[CMFCToolBarImages::IsPreMultiplyAutoCheck](#ispremultiplyautocheck)||  
|[CMFCToolBarImages::IsRTL](#isrtl)|Determina se o suporte a direita para a esquerda (RTL) está habilitado.|  
|[CMFCToolBarImages::IsReadOnly](#isreadonly)|Determina se as imagens da barra de ferramentas são somente leitura.|  
|[CMFCToolBarImages::IsScaled](#isscaled)|Indica se as imagens sublinhadas são dimensionadas ou não.|  
|[CMFCToolBarImages::IsUserImagesList](#isuserimageslist)|Determina se este conjunto de imagens de barra de ferramentas contém imagens definidas pelo usuário.|  
|[CMFCToolBarImages::IsValid](#isvalid)|Determina se este conjunto de imagens de barra de ferramentas contém uma imagem válida da barra de ferramentas.|  
|[CMFCToolBarImages::Load](#load)|Carrega imagens da barra de ferramentas de recursos do sistema ou de um arquivo.|  
|[CMFCToolBarImages::LoadStr](#loadstr)||  
|[CMFCToolBarImages::MapFromSysColor](#mapfromsyscolor)||  
|[CMFCToolBarImages::MapTo3dColors](#mapto3dcolors)||  
|[CMFCToolBarImages::MapToSysColor](#maptosyscolor)||  
|[CMFCToolBarImages::MapToSysColorAlpha](#maptosyscoloralpha)||  
|[CMFCToolBarImages::Mirror](#mirror)|Horizontalmente espelha todas as imagens da barra de ferramentas.|  
|[CMFCToolBarImages::MirrorBitmap](#mirrorbitmap)|Espelha horizontalmente um bitmap.|  
|[CMFCToolBarImages::MirrorBitmapVert](#mirrorbitmapvert)||  
|[CMFCToolBarImages::MirrorVert](#mirrorvert)||  
|[CMFCToolBarImages::OnSysColorChange](#onsyscolorchange)||  
|[CMFCToolBarImages::PrepareDrawImage](#preparedrawimage)|Aloca os recursos necessários para desenhar uma imagem da barra de ferramentas em um tamanho especificado.|  
|[CMFCToolBarImages::Save](#save)|Armazena as imagens da barra de ferramentas em um arquivo se este conjunto de imagens da barra de ferramentas contém imagens definidas pelo usuário.|  
|[CMFCToolBarImages::SetAlwaysLight](#setalwayslight)||  
|[CMFCToolBarImages::SetDisabledImageAlpha](#setdisabledimagealpha)|Define o valor de canal alfa é usado para imagens desabilitadas.|  
|[CMFCToolBarImages::SetFadedImageAlpha](#setfadedimagealpha)||  
|[CMFCToolBarImages::SetImageSize](#setimagesize)|Define o tamanho de uma imagem da barra de ferramentas (tamanho da fonte).|  
|[CMFCToolBarImages::SetLightPercentage](#setlightpercentage)||  
|[CMFCToolBarImages::SetMapTo3DColors](#setmapto3dcolors)||  
|[CMFCToolBarImages::SetPreMultiplyAutoCheck](#setpremultiplyautocheck)||  
|[CMFCToolBarImages::SetSingleImage](#setsingleimage)||  
|[CMFCToolBarImages::SetTransparentColor](#settransparentcolor)|Define a cor transparente das imagens da barra de ferramentas.|  
|[CMFCToolBarImages::SmoothResize](#smoothresize)|Sem problemas redimensiona imagens sublinhadas.|  
|[CMFCToolBarImages::UpdateImage](#updateimage)|Atualiza uma imagem da barra de ferramentas definidas pelo usuário de um bitmap.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBarImages::PreMultiplyAlpha](#premultiplyalpha)||  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBarImages::m_bDisableTrueColorAlpha](#m_bdisabletruecoloralpha)|`TRUE`Se alfa truecolor (cor de&32; bits) de mesclagem está desabilitada.|  
  
## <a name="remarks"></a>Comentários  
 O bitmap completo da barra de ferramentas imagens gerenciadas pelo `CMFCToolbarImages` consiste em uma ou mais imagens de pequena barra de ferramentas (botões) de tamanho fixo.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como configurar um `CMFCToolBarImages` objeto usando vários métodos na `CMFCToolBarImages` classe. O exemplo mostra como definir o tamanho da imagem da barra de ferramentas, carregar uma imagem e definir a cor transparente da imagem. Este trecho de código é parte do [exemplo de demonstração do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[32 NVC_MFC_VisualStudioDemo](../../mfc/codesnippet/cpp/cmfctoolbarimages-class_1.h)]  
[!code-cpp[33 NVC_MFC_VisualStudioDemo](../../mfc/codesnippet/cpp/cmfctoolbarimages-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CMFCToolBarImages`   
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtoolbarimages.h  
  
##  <a name="a-nameadaptcolorsa--cmfctoolbarimagesadaptcolors"></a><a name="adaptcolors"></a>CMFCToolBarImages::AdaptColors  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void AdaptColors(
    COLORREF clrBase,  
    COLORREF clrTone);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `clrBase`  
 [in] `clrTone`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameaddicona--cmfctoolbarimagesaddicon"></a><a name="addicon"></a>CMFCToolBarImages::AddIcon  
 Adiciona um ícone para a lista de imagens da barra de ferramentas.  
  
```  
int AddIcon(
    HICON hIcon,  
    BOOL bAlphaBlend=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hIcon`  
 Um identificador para o ícone a ser adicionado.  
  
 [in] `bAlphaBlend`  
 `TRUE`Se esse ícone é usado com combinação alfa; Caso contrário, `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero da imagem da barra de ferramentas que foi adicionado se o método for bem-sucedido; Caso contrário, retornará-1.  
  
##  <a name="a-nameaddimagea--cmfctoolbarimagesaddimage"></a><a name="addimage"></a>CMFCToolBarImages::AddImage  
 Adiciona um bitmap para as imagens da barra de ferramentas.  
  
```  
int AddImage(
    HBITMAP hbmp,  
    BOOL bSetBitPerPixel=FALSE);

int AddImage(
    const CMFCToolBarImages& imageList,  
    int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hbmp`  
 O identificador para o bitmap para adicionar.  
  
 [in] `bSetBitPerPixel`  
 `TRUE`Se o `CMFCToolBarImages` objeto usa a intensidade de cor (bits por pixel) da nova imagem. `FALSE` se o `CMFCToolbarImages` objeto mantém a intensidade de cor atual.  
  
 [in] `imageList`  
 Uma referência a um `CMFCToolbarImages` objeto que contém a imagem para adicionar.  
  
 [in] `nIndex`  
 O índice da fonte de `CMFCToolbarImages` objeto da imagem para adicionar.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de barra de ferramentas imagens que o `CMFCToolBarImages` objeto mantém depois que o novo bitmap foi adicionado com êxito; -1 se a operação falhou.  
  
##  <a name="a-namecleanupa--cmfctoolbarimagescleanup"></a><a name="cleanup"></a>CMFCToolBarImages::CleanUp  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
static void __stdcall CleanUp();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namecleara--cmfctoolbarimagesclear"></a><a name="clear"></a>CMFCToolBarImages::Clear  
 Libera os recursos do sistema que o [CMFCToolbarImages](../../mfc/reference/cmfctoolbarimages-class.md) objeto alocado.  
  
```  
void Clear();
```  
  
##  <a name="a-namecmfctoolbarimagesa--cmfctoolbarimagescmfctoolbarimages"></a><a name="cmfctoolbarimages"></a>CMFCToolBarImages::CMFCToolBarImages  
 Constrói um objeto `CMFCToolBarImages`.  
  
```  
CMFCToolBarImages();
```  
  
### <a name="remarks"></a>Comentários  
 Constrói um `CMFCToolBarImages` do objeto, inicializa seu mecanismo de renderização e define o tamanho da imagem para o valor padrão 15 x 16 pixels. Use [CMFCToolBarImages::SetImageSize](#setimagesize) para alterar o tamanho da imagem antes de adicionar imagens.  
  
##  <a name="a-namecopyimagetoclipboarda--cmfctoolbarimagescopyimagetoclipboard"></a><a name="copyimagetoclipboard"></a>CMFCToolBarImages::CopyImageToClipboard  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL CopyImageToClipboard(int iImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iImage`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namecopytoa--cmfctoolbarimagescopyto"></a><a name="copyto"></a>CMFCToolBarImages::CopyTo  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL CopyTo(CMFCToolBarImages& imageList);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `imageList`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namecreatefromimagelista--cmfctoolbarimagescreatefromimagelist"></a><a name="createfromimagelist"></a>CMFCToolBarImages::CreateFromImageList  
 Inicializa as imagens da barra de ferramentas de um [classe CImageList](../../mfc/reference/cimagelist-class.md) objeto.  
  
```  
BOOL CreateFromImageList(const CImageList& imageList);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `imageList`  
 A lista de imagem a ser usado como uma fonte para imagens de barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para inicializar rapidamente a lista de imagens de barra de ferramentas de uma lista de imagens externas.  
  
##  <a name="a-namecreateregionfromimagea--cmfctoolbarimagescreateregionfromimage"></a><a name="createregionfromimage"></a>CMFCToolBarImages::CreateRegionFromImage  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
static HRGN __stdcall CreateRegionFromImage(
    HBITMAP bmp,  
    COLORREF clrTransparent);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bmp`  
 [in] `clrTransparent`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namedeleteimagea--cmfctoolbarimagesdeleteimage"></a><a name="deleteimage"></a>CMFCToolBarImages::DeleteImage  
 Exclui a imagem definida pelo usuário que tem um índice especificado entre as imagens da barra de ferramentas.  
  
```  
BOOL DeleteImage(int iImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iImage`  
 Especifica o índice baseado em zero da imagem para excluir.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a imagem foi excluída com êxito; `FALSE` se o índice de imagem for inválido, o `CMFCToolbarImages` objeto é temporário, o `CMFCToolbarImages` objeto não contém imagens definidas pelo usuário, ou se algum outro erro ocorreu.  
  
##  <a name="a-namedrawa--cmfctoolbarimagesdraw"></a><a name="draw"></a>CMFCToolBarImages::Draw  
 Desenha uma imagem única barra de ferramentas.  
  
```  
BOOL Draw(
    CDC* pDC,  
    int x,  
    int y,  
    int iImageIndex,  
    BOOL bHilite=FALSE,  
    BOOL bDisabled=FALSE,  
    BOOL bIndeterminate=FALSE,  
    BOOL bShadow=FALSE,  
    BOOL bInactive=FALSE,  
    BYTE alphaSrc=255);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `x`  
 A coordenada X do lado esquerdo do retângulo onde a imagem deve ser desenhada.  
  
 [in] `y`  
 A coordenada Y da parte superior do retângulo onde a imagem deve ser desenhada.  
  
 [in] `iImageIndex`  
 O índice baseado em zero da imagem a ser exibida.  
  
 [in] `bHilite`  
 `TRUE`Se a imagem deve ser realçada; Caso contrário, `FALSE`.  
  
 [in] `bDisabled`  
 `TRUE`Se a imagem a ser desenhada no estilo desabilitado; Caso contrário, `FALSE`.  
  
 [in] `bIndeterminate`  
 `TRUE`Se a imagem deve ser desenhada no estilo estado indeterminado; Caso contrário, `FALSE`.  
  
 [in] `bShadow`  
 `TRUE`Se a imagem deve ser desenhada com uma sombra; Caso contrário, `FALSE`.  
  
 [in] `bInactive`  
 `TRUE`Se a imagem deve ser desenhada no estilo estado inativo; Caso contrário, `FALSE`.  
  
 [in] `alphaSrc`  
 O valor de canal alfa (opacity). Um valor de 255 significa que a imagem é desenhado opaco. Um valor de 0 significa que a imagem é desenhada transparente. Esse valor é usado apenas para imagens coloridas de 32 bits e para imagens exibidas um estilo de vidro do Windows Vista.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a imagem especificada foi exibida com êxito; `FALSE` se o índice de imagem era inválido ou ocorreu algum outro erro.  
  
##  <a name="a-namedrawexa--cmfctoolbarimagesdrawex"></a><a name="drawex"></a>CMFCToolBarImages::DrawEx  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL DrawEx(
    CDC* pDC,  
    CRect rect,  
    int iImageIndex,  
    ImageAlignHorz horzAlign = ImageAlignHorzLeft,  
    ImageAlignVert vertAlign = ImageAlignVertTop,  
    CRect rectSrc = CRect(0,
    0,
    0,
    0),  
    BYTE alphaSrc = 255);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 [in] `rect`  
 [in] `iImageIndex`  
 [in] `horzAlign`  
 [in] `vertAlign`  
 [in] `rectSrc`  
 [in] `0`  
 [in] `0)`  
 [in] `alphaSrc`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameenablertla--cmfctoolbarimagesenablertl"></a><a name="enablertl"></a>CMFCToolBarImages::EnableRTL  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
static void __stdcall EnableRTL(BOOL bIsRTL = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bIsRTL`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameenddrawimagea--cmfctoolbarimagesenddrawimage"></a><a name="enddrawimage"></a>CMFCToolBarImages::EndDrawImage  
 Libera recursos do sistema que [CMFCToolBarImages::PrepareDrawImage](#preparedrawimage) alocados depois de desenhar uma imagem da barra de ferramentas chamando [CMFCToolBarImages::Draw](#draw).  
  
```  
void EndDrawImage(CAfxDrawState& ds);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `ds`  
 Uma referência para o `CAfxDrawState` objeto que foi passado para o `PrepareDrawImage` método.  
  
##  <a name="a-nameextracticona--cmfctoolbarimagesextracticon"></a><a name="extracticon"></a>CMFCToolBarImages::ExtractIcon  
 Retorna o ícone que tem um índice de imagem especificado entre as imagens da barra de ferramentas.  
  
```  
HICON ExtractIcon(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 O índice baseado em zero na lista de imagens em que a imagem a ser extraído como um ícone está localizada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o ícone extraído, ou `NULL` se `nIndex` está fora do intervalo.  
  
##  <a name="a-namefillditheredrecta--cmfctoolbarimagesfillditheredrect"></a><a name="fillditheredrect"></a>CMFCToolBarImages::FillDitheredRect  
 Preenche um retângulo com as cores de plano de fundo da barra de ferramentas.  
  
```  
static void FillDitheredRect(
    CDC* pDC,  
    const CRect& rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `rect`  
 As coordenadas de um retângulo para preencher.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para preencher um retângulo com uma cor que é a média das cores do sistema COLOR_BTNFACE e COLOR_BTNHIGHLIGHT. Se o sistema está usando 256 cores ou menos, o retângulo será preenchido com um padrão pontilhado dessas duas cores em vez disso.  
  
##  <a name="a-namegetalwayslighta--cmfctoolbarimagesgetalwayslight"></a><a name="getalwayslight"></a>CMFCToolBarImages::GetAlwaysLight  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL GetAlwaysLight() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetcounta--cmfctoolbarimagesgetcount"></a><a name="getcount"></a>CMFCToolBarImages::GetCount  
 Retorna o número de imagens na lista de imagens da barra de ferramentas.  
  
```  
int GetCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de imagens a `CMFCToolBarImages` objeto.  
  
##  <a name="a-namegetdisabledimagealphaa--cmfctoolbarimagesgetdisabledimagealpha"></a><a name="getdisabledimagealpha"></a>CMFCToolBarImages::GetDisabledImageAlpha  
 Retorna o valor de canal alfa (opacity) que é usado para imagens desabilitadas.  
  
```  
static BYTE GetDisabledImageAlpha();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor atual do canal alfa.  
  
### <a name="remarks"></a>Comentários  
 Você pode chamar [CMFCToolBarImages::SetDisabledImageAlpha](#setdisabledimagealpha) para alterar o valor de canal alfa.  
  
##  <a name="a-namegetfadedimagealphaa--cmfctoolbarimagesgetfadedimagealpha"></a><a name="getfadedimagealpha"></a>CMFCToolBarImages::GetFadedImageAlpha  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
static BYTE __stdcall GetFadedImageAlpha();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetimagesizea--cmfctoolbarimagesgetimagesize"></a><a name="getimagesize"></a>CMFCToolBarImages::GetImageSize  
 Recupera o tamanho das imagens da barra de ferramentas que são armazenados na memória (tamanho da fonte) ou o tamanho das imagens da barra de ferramentas que são desenhadas na tela (tamanho de destino).  
  
```  
SIZE GetImageSize(BOOL bDest=FALSE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bDest`  
 `TRUE`para recuperar o tamanho de destino. `FALSE` para recuperar o tamanho da imagem de origem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `SIZE` estrutura, que especifica o tamanho de uma imagem em pixels.  
  
### <a name="remarks"></a>Comentários  
 O tamanho da imagem de origem é o tamanho das imagens que são armazenados na [CMFCToolbarImages](../../mfc/reference/cmfctoolbarimages-class.md) objeto. Você pode chamar [CMFCToolBarImages::SetImageSize](#setimagesize) para definir o tamanho da fonte. O valor padrão é 15 x 16 pixels.  
  
 Por padrão, o tamanho da imagem de destino é 0x0. Especifique o tamanho de destino quando você chama [CMFCToolBarImages::PrepareDrawImage](#preparedrawimage). O [CMFCToolBarImages::EndDrawImage](#enddrawimage) método redefine o tamanho de destino para o valor padrão.  
  
##  <a name="a-namegetimagewella--cmfctoolbarimagesgetimagewell"></a><a name="getimagewell"></a>CMFCToolBarImages::GetImageWell  
 Retorna o identificador para o bitmap que contém todas as imagens da barra de ferramentas.  
  
```  
HBITMAP GetImageWell() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para um bitmap que contém imagens da barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 As imagens da barra de ferramentas são armazenadas em uma linha em um único bitmap é conhecido como um *imagem bem*. Para localizar uma imagem da barra de ferramentas no espaço de imagem, multiplique o índice da imagem usando a largura das imagens da barra de ferramentas (consulte [CMFCToolBarImages::GetImageSize](#getimagesize)) para obter o deslocamento horizontal da imagem na imagem também.  
  
##  <a name="a-namegetimagewelllighta--cmfctoolbarimagesgetimagewelllight"></a><a name="getimagewelllight"></a>CMFCToolBarImages::GetImageWellLight  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
HBITMAP GetImageWellLight() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetlastimagerecta--cmfctoolbarimagesgetlastimagerect"></a><a name="getlastimagerect"></a>CMFCToolBarImages::GetLastImageRect  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CRect GetLastImageRect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetlightpercentagea--cmfctoolbarimagesgetlightpercentage"></a><a name="getlightpercentage"></a>CMFCToolBarImages::GetLightPercentage  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
int GetLightPercentage() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetmapto3dcolorsa--cmfctoolbarimagesgetmapto3dcolors"></a><a name="getmapto3dcolors"></a>CMFCToolBarImages::GetMapTo3DColors  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL GetMapTo3DColors() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetmaska--cmfctoolbarimagesgetmask"></a><a name="getmask"></a>CMFCToolBarImages::GetMask  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
HBITMAP GetMask(int iImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iImage`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetresourceoffseta--cmfctoolbarimagesgetresourceoffset"></a><a name="getresourceoffset"></a>CMFCToolBarImages::GetResourceOffset  
 Retorna o índice de imagem para uma ID de recurso especificado.  
  
```  
int GetResourceOffset(UINT uiResId) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiResId`  
 Uma ID de recurso de imagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um índice de imagem se o método teve êxito; -1 se a imagem com a ID de recurso especificado não existe.  
  
##  <a name="a-namegettransparentcolora--cmfctoolbarimagesgettransparentcolor"></a><a name="gettransparentcolor"></a>CMFCToolBarImages::GetTransparentColor  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
COLORREF GetTransparentColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegrayimagesa--cmfctoolbarimagesgrayimages"></a><a name="grayimages"></a>CMFCToolBarImages::GrayImages  
 Grays as imagens da barra de ferramentas para torná-las desabilitado.  
  
```  
BOOL GrayImages(int nGrayImageLuminancePercentage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nGrayImageLuminancePercentage`  
 Porcentagem de luminância.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se as imagens na coleção foram desabilitadas com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método modifica as imagens da barra de ferramentas média entre os componentes vermelhos, verde e azuis de cada pixel e multiplicando o resultado pelo `nGrayImageLuminancePercentage` dividido por 100. Se `nGrayImageLuminancePercentage` for zero ou negativo, o valor padrão de 130 é usado em vez disso.  
  
> [!NOTE]
>  Se você quiser desfazer a alteração, recarregue as imagens da origem. Você pode fazer isso chamando [CMFCToolBarImages::Load](#load) ou [CMFCToolBarImages::UpdateImage](#updateimage) (somente para definido pelo usuário imagens), ou chamando [CMFCToolBarImages::Clear](#clear) e adicionando as imagens novamente chamando [CMFCToolBarImages::AddIcon](#addicon) ou [CMFCToolBarImages::AddImage](#addimage).  
  
##  <a name="a-nameis32bittransparencysupporteda--cmfctoolbarimagesis32bittransparencysupported"></a><a name="is32bittransparencysupported"></a>CMFCToolBarImages::Is32BitTransparencySupported  
 Especifica se o sistema operacional oferece suporte a combinação alfa de 32 bits.  
  
```  
static BOOL Is32BitTransparencySupported();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se houver suporte para a combinação alfa de 32 bits; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método estático para determinar em tempo de execução se o sistema operacional oferece suporte a combinação alfa de 32 bits. Esse recurso tem suporte em [!INCLUDE[Win2kFamily](../../c-runtime-library/includes/win2kfamily_md.md)] e versões posteriores.  
  
##  <a name="a-nameispremultiplyautochecka--cmfctoolbarimagesispremultiplyautocheck"></a><a name="ispremultiplyautocheck"></a>CMFCToolBarImages::IsPreMultiplyAutoCheck  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL IsPreMultiplyAutoCheck() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisreadonlya--cmfctoolbarimagesisreadonly"></a><a name="isreadonly"></a>CMFCToolBarImages::IsReadOnly  
 Especifica se as imagens da barra de ferramentas são somente leitura.  
  
```  
BOOL IsReadOnly() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se as imagens da barra de ferramentas são somente leitura, caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O `CMFCToolbarImages` objeto é somente leitura quando o bitmap com imagens da barra de ferramentas foi carregado de um arquivo somente leitura, ou quando o bitmap foi copiado usando o `CMFCToolBarImages::CopyTemp` método.  
  
##  <a name="a-nameisrtla--cmfctoolbarimagesisrtl"></a><a name="isrtl"></a>CMFCToolBarImages::IsRTL  
 Especifica se o suporte a direita para a esquerda (RTL) está habilitado.  
  
```  
static BOOL IsRTL();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o suporte a RTL estiver habilitado; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Suporte a RTL é usado quando o aplicativo for localizado para um idioma que é lido da direita para a esquerda, como árabe, hebraico, persa e Urdu.  
  
##  <a name="a-nameisuserimageslista--cmfctoolbarimagesisuserimageslist"></a><a name="isuserimageslist"></a>CMFCToolBarImages::IsUserImagesList  
 Especifica se este conjunto de imagens de barra de ferramentas contém imagens definidas pelo usuário.  
  
```  
BOOL IsUserImagesList() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o `CMFCToolBarImages` objeto contém imagens da barra de ferramentas definidas pelo usuário; caso contrário, `FALSE`.  
  
##  <a name="a-nameisvalida--cmfctoolbarimagesisvalid"></a><a name="isvalid"></a>CMFCToolBarImages::IsValid  
 Indica se este conjunto de imagens de barra de ferramentas contém uma imagem válida da barra de ferramentas.  
  
```  
BOOL IsValid() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se um `CMFCToolBarImages` objeto for válido; caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O `CMFCToolBarImages` objeto não é válido quando seu identificador para um bitmap com imagens da barra de ferramentas é `NULL`.  
  
##  <a name="a-nameloada--cmfctoolbarimagesload"></a><a name="load"></a>CMFCToolBarImages::Load  
 Carrega imagens da barra de ferramentas de recursos do sistema ou de um arquivo.  
  
```  
BOOL Load(
    UINT uiResID,  
    HINSTANCE hinstRes=NULL,  
    BOOL bAdd=FALSE);

BOOL Load(
    LPCTSTR lpszBmpFileName,   
    DWORD nMaxFileSize = 819200);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiResID`  
 A ID de um recurso de bitmap.  
  
 [in] `hinstRes`  
 Uma instância da DLL do recurso.  
  
 [in] `bAdd`  
 `TRUE`Para adicionar o bitmap carregado no bitmap existente, ou `FALSE` para substituir o bitmap existente.  
  
 [in] `lpszBmpFileName`  
 Um caminho para um arquivo de disco da qual carregar o bitmap.  
  
 [in] `nMaxFileSize`  
 Número máximo de bytes no arquivo de bitmap; ou 0 para carregar o bitmap, independentemente do tamanho do arquivo. Se o tamanho do arquivo exceder esse tamanho máximo, o método retorna `FALSE` e não carregar o bitmap.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o bitmap foi carregado com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Se o arquivo tem o atributo somente leitura, a lista de imagens é marcada como somente leitura.  
  
##  <a name="a-nameloadstra--cmfctoolbarimagesloadstr"></a><a name="loadstr"></a>CMFCToolBarImages::LoadStr  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL LoadStr(
    LPCTSTR lpszResourceName,  
    HINSTANCE hinstRes = NULL,  
    BOOL bAdd = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszResourceName`  
 [in] `hinstRes`  
 [in] `bAdd`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namemapfromsyscolora--cmfctoolbarimagesmapfromsyscolor"></a><a name="mapfromsyscolor"></a>CMFCToolBarImages::MapFromSysColor  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
static COLORREF __stdcall MapFromSysColor(
    COLORREF color,  
    BOOL bUseRGBQUAD = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `color`  
 [in] `bUseRGBQUAD`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namemapto3dcolorsa--cmfctoolbarimagesmapto3dcolors"></a><a name="mapto3dcolors"></a>CMFCToolBarImages::MapTo3dColors  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL MapTo3dColors(
    BOOL bUseRGBQUAD = TRUE,  
    COLORREF clrSrc = (COLORREF)-1,  
    COLORREF clrDest = (COLORREF)-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bUseRGBQUAD`  
 [in] `clrSrc`  
 [in] `clrDest`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namemaptosyscolora--cmfctoolbarimagesmaptosyscolor"></a><a name="maptosyscolor"></a>CMFCToolBarImages::MapToSysColor  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
static COLORREF __stdcall MapToSysColor(
    COLORREF color,  
    BOOL bUseRGBQUAD = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `color`  
 [in] `bUseRGBQUAD`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namemaptosyscoloralphaa--cmfctoolbarimagesmaptosyscoloralpha"></a><a name="maptosyscoloralpha"></a>CMFCToolBarImages::MapToSysColorAlpha  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
static COLORREF __stdcall MapToSysColorAlpha(COLORREF color);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `color`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namemirrora--cmfctoolbarimagesmirror"></a><a name="mirror"></a>CMFCToolBarImages::Mirror  
 Substitui as imagens da barra de ferramentas com sua imagem espelhada horizontal.  
  
```  
BOOL Mirror();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se as imagens foram espelhadas com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método é usado para oferecer suporte a sistemas de escrita da direita para a esquerda.  
  
##  <a name="a-namemirrorbitmapa--cmfctoolbarimagesmirrorbitmap"></a><a name="mirrorbitmap"></a>CMFCToolBarImages::MirrorBitmap  
 Substitui um bitmap com a imagem espelhada horizontal.  
  
```  
static BOOL MirrorBitmap(
    HBITMAP& hbmp,  
    int cxImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in, out] `hbmp`  
 Um identificador de bitmap para espelhar.  
  
 [in] `cxImage`  
 Largura da imagem em pixels.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a imagem foi espelhada com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Essa função é usada para oferecer suporte a sistemas de escrita da direita para a esquerda.  
  
##  <a name="a-namemirrorbitmapverta--cmfctoolbarimagesmirrorbitmapvert"></a><a name="mirrorbitmapvert"></a>CMFCToolBarImages::MirrorBitmapVert  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
static BOOL __stdcall MirrorBitmapVert(
    HBITMAP& hbmp,  
    int cyImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hbmp`  
 [in] `cyImage`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namemirrorverta--cmfctoolbarimagesmirrorvert"></a><a name="mirrorvert"></a>CMFCToolBarImages::MirrorVert  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL MirrorVert();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonsyscolorchangea--cmfctoolbarimagesonsyscolorchange"></a><a name="onsyscolorchange"></a>CMFCToolBarImages::OnSysColorChange  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void OnSysColorChange();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namepremultiplyalphaa--cmfctoolbarimagespremultiplyalpha"></a><a name="premultiplyalpha"></a>CMFCToolBarImages::PreMultiplyAlpha  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
static BOOL __stdcall PreMultiplyAlpha(
    HBITMAP hbmp,  
    BOOL bAutoCheckPremlt);

BOOL PreMultiplyAlpha(HBITMAP hbmp);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hbmp`  
 [in] `bAutoCheckPremlt`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namembdisabletruecoloralphaa--cmfctoolbarimagesmbdisabletruecoloralpha"></a><a name="m_bdisabletruecoloralpha"></a>CMFCToolBarImages::m_bDisableTrueColorAlpha  
 `TRUE`Se alfa truecolor (cor de&32; bits) de mesclagem está desabilitada.  
  
```  
static BOOL m_bDisableTrueColorAlpha;  
```  
  
### <a name="remarks"></a>Comentários  
 Definir essa variável de membro como `FALSE` para habilitar truecolor transparência para imagens de barra de ferramentas.  
  
 O valor padrão é `TRUE` para compatibilidade com versões anteriores.  
  
##  <a name="a-namepreparedrawimagea--cmfctoolbarimagespreparedrawimage"></a><a name="preparedrawimage"></a>CMFCToolBarImages::PrepareDrawImage  
 Aloca os recursos necessários para desenhar uma imagem da barra de ferramentas em um tamanho especificado.  
  
```  
BOOL PrepareDrawImage(
    CAfxDrawState& ds,  
    CSize sizeImageDest=CSize(0,
    0)  
    BOOL bFadeInactive=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `ds`  
 Uma referência a `CAfxDrawState` estrutura, que armazena os recursos alocados entre os estágios de processamento de imagem.  
  
 [in] `sizeImageDest`  
 Especifica o tamanho de uma imagem de destino.  
  
 [in] `bFadeInactive`  
 `TRUE`Se você quiser inativo atenuado imagens a ser desenhada.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se os recursos necessários para desenhar a imagem da barra de ferramentas foram alocados com êxito, caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Depois de chamar esse método, você pode chamar [CMFCToolBarImages::Draw](#draw) qualquer número de vezes. Depois que você terminar o desenho, você deve chamar [CMFCToolBarImages::EndDrawImage](#enddrawimage) para liberar os recursos alocados pelo `PrepareDrawImage`.  
  
##  <a name="a-namesavea--cmfctoolbarimagessave"></a><a name="save"></a>CMFCToolBarImages::Save  
 Armazena as imagens da barra de ferramentas em um arquivo se este conjunto de imagens da barra de ferramentas contém imagens definidas pelo usuário.  
  
```  
BOOL Save(LPCTSTR lpszBmpFileName=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszBmpFileName`  
 Um caminho para um arquivo de disco.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se as imagens da barra de ferramentas foram salvas com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para armazenar as imagens definidas pelo usuário em um arquivo de disco. Se `lpszBmpFileName` é `NULL`, o método armazena o bitmap no arquivo do qual o bitmap foi carregado pelo [CMFCToolBarImages::Load](#load) método.  
  
##  <a name="a-namesetalwayslighta--cmfctoolbarimagessetalwayslight"></a><a name="setalwayslight"></a>CMFCToolBarImages::SetAlwaysLight  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void SetAlwaysLight(BOOL bAlwaysLight = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bAlwaysLight`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetdisabledimagealphaa--cmfctoolbarimagessetdisabledimagealpha"></a><a name="setdisabledimagealpha"></a>CMFCToolBarImages::SetDisabledImageAlpha  
 Define o valor de canal alfa (opacity) que é usado para imagens desabilitadas.  
  
```  
static void SetDisabledImageAlpha(BYTE nValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nValue`  
 O novo valor do canal alfa.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para definir um valor alfa personalizado de imagens desabilitados. O valor padrão é de 127, que faz com que as imagens de botões desabilitados ser semitransparente. Se você definir um valor de 0, desabilitadas imagens será completamente transparentes. Se você definir um valor de 255, imagens desabilitadas será completamente opacas.  
  
##  <a name="a-namesetfadedimagealphaa--cmfctoolbarimagessetfadedimagealpha"></a><a name="setfadedimagealpha"></a>CMFCToolBarImages::SetFadedImageAlpha  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
static void __stdcall SetFadedImageAlpha(BYTE nValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nValue`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetimagesizea--cmfctoolbarimagessetimagesize"></a><a name="setimagesize"></a>CMFCToolBarImages::SetImageSize  
 Define o tamanho de cada imagem de barra de ferramentas (tamanho da fonte).  
  
```  
void SetImageSize(
    SIZE sizeImage,  
    BOOL bUpdateCount=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `sizeImage`  
 O novo tamanho das imagens da barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Por padrão o tamanho da imagem da barra de ferramentas é 15 x 16 pixels. Chame esse método se você quiser usar as imagens da barra de ferramentas de um tamanho diferente.  
  
##  <a name="a-namesetlightpercentagea--cmfctoolbarimagessetlightpercentage"></a><a name="setlightpercentage"></a>CMFCToolBarImages::SetLightPercentage  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void SetLightPercentage(int nValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nValue`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetmapto3dcolorsa--cmfctoolbarimagessetmapto3dcolors"></a><a name="setmapto3dcolors"></a>CMFCToolBarImages::SetMapTo3DColors  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void SetMapTo3DColors(BOOL bMapTo3DColors);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bMapTo3DColors`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetpremultiplyautochecka--cmfctoolbarimagessetpremultiplyautocheck"></a><a name="setpremultiplyautocheck"></a>CMFCToolBarImages::SetPreMultiplyAutoCheck  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void SetPreMultiplyAutoCheck(BOOL bAuto = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bAuto`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetsingleimagea--cmfctoolbarimagessetsingleimage"></a><a name="setsingleimage"></a>CMFCToolBarImages::SetSingleImage  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void SetSingleImage();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesettransparentcolora--cmfctoolbarimagessettransparentcolor"></a><a name="settransparentcolor"></a>CMFCToolBarImages::SetTransparentColor  
 Define a cor transparente das imagens da barra de ferramentas.  
  
```  
COLORREF SetTransparentColor(COLORREF clrTransparent);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `clrTransparent`  
 Um valor RGB.  
  
### <a name="return-value"></a>Valor de retorno  
 A cor transparente anterior.  
  
### <a name="remarks"></a>Comentários  
 Quando você ou o framework chama [CMFCToolBarImages::Draw](#draw), o método não desenhar qualquer pixel que coincide com a cor especificada pela `clrTransparent`.  
  
##  <a name="a-nameupdateimagea--cmfctoolbarimagesupdateimage"></a><a name="updateimage"></a>CMFCToolBarImages::UpdateImage  
 Atualiza uma imagem da barra de ferramentas definidas pelo usuário de um bitmap.  
  
```  
BOOL UpdateImage(
    int iImage,  
    HBITMAP hbmp);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iImage`  
 O índice baseado em zero da imagem para atualizar.  
  
 [in] `hbmp`  
 Um identificador para o bitmap do qual atualizar a imagem.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a imagem foi atualizada com êxito; `FALSE` se a lista de imagens não é definido pelo usuário ou temporária.  
  
##  <a name="a-nameconvertto32bitsa--cmfctoolbarimagesconvertto32bits"></a><a name="convertto32bits"></a>CMFCToolBarImages::ConvertTo32Bits  
 Converte sublinhado bitmaps 32 bpp imagens.  
  
```  
BOOL ConvertTo32Bits(COLORREF clrTransparent = (COLORREF)-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `clrTransparent`  
 Especifica a cor transparente da bitmaps sublinhado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetbitsperpixela--cmfctoolbarimagesgetbitsperpixel"></a><a name="getbitsperpixel"></a>CMFCToolBarImages::GetBitsPerPixel  
 Retorna a resolução atual de imagens de sublinhado.  
  
```  
int GetBitsPerPixel() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor inteiro que representa a resolução atual de imagens sublinhadas, em bits por pixel (bpp).  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetscalea--cmfctoolbarimagesgetscale"></a><a name="getscale"></a>CMFCToolBarImages::GetScale  
 Retorna a taxa atual de escala de imagens de sublinhado.  
  
```  
double GetScale() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que representa a taxa atual de escala.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisscaleda--cmfctoolbarimagesisscaled"></a><a name="isscaled"></a>CMFCToolBarImages::IsScaled  
 Indica se as imagens sublinhadas são dimensionadas ou não.  
  
```  
BOOL IsScaled () const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o sublinhado as imagens são dimensionadas; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesmoothresizea--cmfctoolbarimagessmoothresize"></a><a name="smoothresize"></a>CMFCToolBarImages::SmoothResize  
 Sem problemas redimensiona imagens sublinhadas.  
  
```  
BOOL SmoothResize(double dblImageScale);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dblImageScale`  
 Proporção de escala.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o redimensionamento for bem-sucedida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)   
 [Classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)

