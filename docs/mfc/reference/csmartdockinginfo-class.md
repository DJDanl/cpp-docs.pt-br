---
title: Classe CSmartDockingInfo | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSmartDockingInfo
dev_langs:
- C++
helpviewer_keywords:
- CSmartDockingInfo class
ms.assetid: cab04f38-4bc1-4378-9337-c56fc87fbd68
caps.latest.revision: 27
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 9ae735b202299d26b98ec763f65c3f8772d9b914
ms.lasthandoff: 02/25/2017

---
# <a name="csmartdockinginfo-class"></a>Classe CSmartDockingInfo
Define a aparência dos marcadores de encaixe inteligente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSmartDockingInfo : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CSmartDockingInfo::CSmartDockingInfo`|Construtor padrão.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSmartDockingInfo::CopyTo](#copyto)|Copia os parâmetros de encaixe info inteligente atuais em fornecidas [CSmartDockingInfo](../../mfc/reference/csmartdockinginfo-class.md) objeto.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSmartDockingInfo::m_bUseThemeColorInShading](#m_busethemecolorinshading)|Especifica se deve usar a cor do tema atual quando o framework exibe marcadores de encaixe inteligente.|  
|[CSmartDockingInfo::m_clrBaseBackground](#m_clrbasebackground)|Especifica a cor de base do plano de fundo dos marcadores de encaixe inteligente.|  
|[CSmartDockingInfo::m_clrToneDest](#m_clrtonedest)|Especifica a cor que substitui `m_clrToneSrc` em bitmaps de marcador de encaixe inteligente.|  
|[CSmartDockingInfo::m_clrToneSrc](#m_clrtonesrc)|Especifica a cor dos bitmaps de marcador de encaixe inteligente.|  
|[CSmartDockingInfo::m_clrTransparent](#m_clrtransparent)|Especifica a cor dos bitmaps de marcador de encaixe inteligente quando eles são transparentes.|  
|[CSmartDockingInfo::m_nCentralGroupOffset](#m_ncentralgroupoffset)|Especifica o deslocamento do grupo central de marcadores de encaixe inteligente dos limites do retângulo do grupo central.|  
|[CSmartDockingInfo::m_sizeTotal](#m_sizetotal)|Especifica o tamanho total de todos os marcadores de encaixe inteligente em um grupo.|  
|[CSmartDockingInfo::m_uiMarkerBmpResID](#m_uimarkerbmpresid)|Define o recurso IDs dos bitmaps que a estrutura usa para marcadores de encaixe inteligente que não são realçadas.|  
|[CSmartDockingInfo::m_uiMarkerLightBmpResID](#m_uimarkerlightbmpresid)|Define o recurso IDs dos bitmaps que a estrutura usa para marcadores de encaixe inteligente que são realçadas.|  
  
## <a name="remarks"></a>Comentários  
 Os identificadores de framework inteligente marcadores de encaixe internamente. A ilustração a seguir mostra os marcadores de encaixe inteligentes padrão:  
  
 ![Padrão marcadores de encaixe inteligente](../../mfc/reference/media/nextsdmarkers.png "nextsdmarkers")  
  
 Nesta figura, a imagem à esquerda mostra um marcador de encaixe inteligente grupo central que não tenha o encaixe para uma guia habilitada. A imagem no meio mostra um marcador de encaixe inteligente da borda direita. A imagem à direita mostra um marcador de encaixe inteligente grupo central que têm o encaixe para uma guia habilitada. O marcador de encaixe inteligente grupo central tem um bitmap principal e cinco inteligente encaixe bitmaps de marcador.  
  
 Você pode personalizar os seguintes parâmetros de marcadores de encaixe inteligente:  
  
-   Cor. Por exemplo, você pode substituir a cor dos marcadores na Figura azul com qualquer cor definida pelo usuário.  
  
-   Cor de transparência.  
  
-   Deslocamento de um marcador de encaixe inteligente no grupo central da borda do retângulo delimitador.  
  
-   O bitmap principal que representa o grupo central.  
  
-   Os bitmaps que representa os marcadores de encaixe inteligentes regulares e realçados.  
  
 A ilustração a seguir mostra um exemplo dos marcadores de encaixe inteligente personalizados:  
  
 ![Personalizado marcadores de encaixe inteligente](../../mfc/reference/media/nextsdmarkerscustom.png "nextsdmarkerscustom")  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CSmartDockingInfo](../../mfc/reference/csmartdockinginfo-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxDockingManager.h  
  
##  <a name="a-namecopytoa--csmartdockinginfocopyto"></a><a name="copyto"></a>CSmartDockingInfo::CopyTo  
 Copia os parâmetros atuais de encaixe inteligentes para fornecidas [CSmartDockingInfo](../../mfc/reference/csmartdockinginfo-class.md) objeto.  
  
```  
void CopyTo(CSmartDockingInfo& params);
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `params`  
 Um objeto do tipo `CSmartDockingInfo` que é preenchida com os parâmetros atuais de encaixe inteligentes.  
  
##  <a name="a-namembusethemecolorinshadinga--csmartdockinginfombusethemecolorinshading"></a><a name="m_busethemecolorinshading"></a>CSmartDockingInfo::m_bUseThemeColorInShading  
 Especifica se deve usar a cor do tema atual quando o framework exibe marcadores de encaixe inteligente.  
  
```  
BOOL m_bUseThemeColorInShading;  
```  
  
### <a name="remarks"></a>Comentários  
 Se `TRUE`, os marcadores são desenhados usando a cor do tema atual; caso contrário, os marcadores são desenhados com uma cor azul clara.  
  
 O valor padrão é `FALSE`.  
  
##  <a name="a-namemclrbasebackgrounda--csmartdockinginfomclrbasebackground"></a><a name="m_clrbasebackground"></a>CSmartDockingInfo::m_clrBaseBackground  
 Especifica a cor de base do plano de fundo dos marcadores de encaixe inteligente.  
  
```  
COLORREF m_clrBaseBackground;  
```  
  
##  <a name="a-namemclrtonedesta--csmartdockinginfomclrtonedest"></a><a name="m_clrtonedest"></a>CSmartDockingInfo::m_clrToneDest  
 Especifica a cor que irá substituir `m_clrToneSrc` em bitmaps de marcador de encaixe inteligente.  
  
```  
COLORREF m_clrToneDest;  
```  
  
### <a name="remarks"></a>Comentários  
 Defina esse valor para alterar a cor do marcador bitmaps programaticamente. Por exemplo, se você quiser alterar a cor dos marcadores padrão fornecidos com o framework, defina esse valor para a cor desejada. Por padrão, [CSmartDockingInfo::m_clrToneSrc](#m_clrtonesrc) é definido como RGB (61, 123, 241) (uma cor azulada).  
  
 Para alterar a cor dos marcadores personalizados, você deve especificar `m_clrToneDest` e `m_clrToneSrc`.  
  
##  <a name="a-namemclrtonesrca--csmartdockinginfomclrtonesrc"></a><a name="m_clrtonesrc"></a>CSmartDockingInfo::m_clrToneSrc  
 Especifica a cor dos bitmaps de marcador de encaixe inteligente.  
  
```  
COLORREF m_clrToneSrc;  
```  
  
### <a name="remarks"></a>Comentários  
 Defina esse valor somente quando você deseja substituir a cor de um bitmap personalizado com outra cor. Você não precisa definir esse valor se você estiver alterando a cor de um padrão (framework fornecido) marcador.  
  
 Use `(COLORREF)-1` para deixar um membro do grupo de encaixe inteligente vazio.  
  
##  <a name="a-namemclrtransparenta--csmartdockinginfomclrtransparent"></a><a name="m_clrtransparent"></a>CSmartDockingInfo::m_clrTransparent  
 Especifica a cor dos bitmaps de marcador de encaixe inteligente quando eles são transparentes.  
  
```  
COLORREF m_clrTransparent;  
```  
  
### <a name="remarks"></a>Comentários  
 Você deve definir esse valor quando você exibe marcadores personalizados e bitmaps personalizados no grupo de encaixe.  
  
##  <a name="a-namemncentralgroupoffseta--csmartdockinginfomncentralgroupoffset"></a><a name="m_ncentralgroupoffset"></a>CSmartDockingInfo::m_nCentralGroupOffset  
 Especifica o deslocamento entre o grupo central de marcadores de encaixe inteligente e os limites do retângulo do grupo central.  
  
```  
int m_nCentralGroupOffset;  
```  
  
### <a name="remarks"></a>Comentários  
 Especifique esse valor se você quiser alterar o deslocamento do padrão entre os limites do grupo central de marcadores de encaixe inteligente e marcadores personalizados. O desvio padrão é 5 pixels.  
  
##  <a name="a-namemsizetotala--csmartdockinginfomsizetotal"></a><a name="m_sizetotal"></a>CSmartDockingInfo::m_sizeTotal  
 Especifica o tamanho total de um retângulo que inclui todos os marcadores de encaixe inteligente no grupo central.  
  
```  
CSize m_sizeTotal;  
```  
  
### <a name="remarks"></a>Comentários  
 Defina `m_sizeTotal` para o tamanho do retângulo delimitador do marcador do grupo central. Você precisa especificar esse valor se você estiver usando bitmaps personalizados de marcadores.  
  
##  <a name="a-namemuimarkerbmpresida--csmartdockinginfomuimarkerbmpresid"></a><a name="m_uimarkerbmpresid"></a>CSmartDockingInfo::m_uiMarkerBmpResID  
 Define o recurso IDs dos bitmaps que são usados para não realçado personalizados marcadores de encaixe inteligente.  
  
```  
UINT m_uiMarkerBmpResID[AFX_SD_MARKERS_NUM];  
```  
  
### <a name="remarks"></a>Comentários  
 Preencha essa matriz com o recurso IDs dos bitmaps que representa os marcadores de encaixe inteligentes. `AFX_SD_MARKERS_NUM`no momento está definido como 5. Você pode preencher a matriz da seguinte maneira:  
  
 `params.m_uiMarkerBmpResID[0] = IDB_MARKER_LEFT;`  
  
 `params.m_uiMarkerBmpResID[1] = IDB_MARKER_RIGHT;`  
  
 `params.m_uiMarkerBmpResID[2] = IDB_MARKER_TOP;`  
  
 `params.m_uiMarkerBmpResID[3] = IDB_MARKER_BOTTOM;`  
  
 `params.m_uiMarkerBmpResID[4] = IDB_MARKER_CENTER;`  
  
##  <a name="a-namemuimarkerlightbmpresida--csmartdockinginfomuimarkerlightbmpresid"></a><a name="m_uimarkerlightbmpresid"></a>CSmartDockingInfo::m_uiMarkerLightBmpResID  
 Define o recurso IDs dos bitmaps que são usados para marcadores de encaixe inteligente personalizados realçados.  
  
```  
UINT m_uiMarkerLightBmpResID[AFX_SD_MARKERS_NUM];  
```  
  
### <a name="remarks"></a>Comentários  
 Preencha essa matriz com o recurso IDs dos bitmaps que representa os marcadores de encaixe inteligentes realçados. `AFX_SD_MARKERS_NUM`no momento está definido como 5. Você pode preencher a matriz da seguinte maneira:  
  
 `params.m_uiMarkerLightBmpResID[0] = IDB_MARKER_LEFT_LIGHT;`  
  
 `params.m_uiMarkerLightBmpResID[1] = IDB_MARKER_RIGHT_LIGHT;`  
  
 `params.m_uiMarkerLightBmpResID[2] = IDB_MARKER_TOP_LIGHT;`  
  
 `params.m_uiMarkerLightBmpResID[3] = IDB_MARKER_BOTTOM_LIGHT;`  
  
 `params.m_uiMarkerLightBmpResID[4] = IDB_MARKER_CENTER_LIGHT;`  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)

