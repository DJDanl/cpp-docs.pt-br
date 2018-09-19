---
title: Classe CSmartDockingInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CSmartDockingInfo
- AFXDOCKINGMANAGER/CSmartDockingInfo
- AFXDOCKINGMANAGER/CSmartDockingInfo::CopyTo
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_bUseThemeColorInShading
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_clrBaseBackground
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_clrToneDest
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_clrToneSrc
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_clrTransparent
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_nCentralGroupOffset
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_sizeTotal
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_uiMarkerBmpResID
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_uiMarkerLightBmpResID
dev_langs:
- C++
helpviewer_keywords:
- CSmartDockingInfo [MFC], CopyTo
- CSmartDockingInfo [MFC], m_bUseThemeColorInShading
- CSmartDockingInfo [MFC], m_clrBaseBackground
- CSmartDockingInfo [MFC], m_clrToneDest
- CSmartDockingInfo [MFC], m_clrToneSrc
- CSmartDockingInfo [MFC], m_clrTransparent
- CSmartDockingInfo [MFC], m_nCentralGroupOffset
- CSmartDockingInfo [MFC], m_sizeTotal
- CSmartDockingInfo [MFC], m_uiMarkerBmpResID
- CSmartDockingInfo [MFC], m_uiMarkerLightBmpResID
ms.assetid: cab04f38-4bc1-4378-9337-c56fc87fbd68
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 653be2fb1847403436bccb86807da382ef09cc25
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46018204"
---
# <a name="csmartdockinginfo-class"></a>Classe CSmartDockingInfo
Define a aparência de marcadores inteligentes de encaixe.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSmartDockingInfo : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CSmartDockingInfo::CSmartDockingInfo`|Construtor padrão.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSmartDockingInfo::CopyTo](#copyto)|Copia os parâmetros de encaixe informações inteligentes atual fornecido [CSmartDockingInfo](../../mfc/reference/csmartdockinginfo-class.md) objeto.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSmartDockingInfo::m_bUseThemeColorInShading](#m_busethemecolorinshading)|Especifica se deve usar a cor do tema atual quando o framework exibe marcadores inteligentes de encaixe.|  
|[CSmartDockingInfo::m_clrBaseBackground](#m_clrbasebackground)|Especifica a cor do plano de fundo de base de marcadores inteligentes de encaixe.|  
|[CSmartDockingInfo::m_clrToneDest](#m_clrtonedest)|Especifica a cor que substitui `m_clrToneSrc` em bitmaps de marcador de encaixe inteligente.|  
|[CSmartDockingInfo::m_clrToneSrc](#m_clrtonesrc)|Especifica a cor do smart bitmaps de marcador de encaixe.|  
|[CSmartDockingInfo::m_clrTransparent](#m_clrtransparent)|Especifica a cor do smart bitmaps de marcador de encaixe quando eles são transparentes.|  
|[CSmartDockingInfo::m_nCentralGroupOffset](#m_ncentralgroupoffset)|Especifica o deslocamento do grupo central de marcadores inteligentes de encaixe dos limites do retângulo de grupo central.|  
|[CSmartDockingInfo::m_sizeTotal](#m_sizetotal)|Especifica o tamanho total de todos os marcadores inteligentes de encaixe em um grupo.|  
|[CSmartDockingInfo::m_uiMarkerBmpResID](#m_uimarkerbmpresid)|Define as IDs dos bitmaps de que a estrutura usa para marcadores inteligentes de encaixe que não estão realçados do recurso.|  
|[CSmartDockingInfo::m_uiMarkerLightBmpResID](#m_uimarkerlightbmpresid)|Define as IDs dos bitmaps de que a estrutura usa para marcadores inteligentes de encaixe que são realçadas do recurso.|  
  
## <a name="remarks"></a>Comentários  
 As alças da estrutura inteligente marcadores de encaixe internamente. A ilustração a seguir mostra os marcadores inteligentes de encaixe padrão:  
  
 ![Marcadores de Standard para encaixar smart](../../mfc/reference/media/nextsdmarkers.png "nextsdmarkers")  
  
 Nesta figura, a imagem à esquerda mostra um marcador de encaixe inteligente grupo central que não tenha de encaixe para uma guia habilitada. A imagem no meio mostra um marcador de encaixe inteligentes de borda direita. A imagem à direita mostra um marcador de encaixe inteligente grupo central que têm o encaixe à guia habilitada. O marcador de encaixe inteligente do grupo central tem um bitmap principal e cinco inteligente encaixe bitmaps de marcador.  
  
 Você pode personalizar os seguintes parâmetros de marcadores inteligentes de encaixe:  
  
-   Cor. Por exemplo, você pode substituir a cor azul dos marcadores na figura com qualquer cor definida pelo usuário.  
  
-   Cor de transparência.  
  
-   Deslocamento de um marcador de encaixe inteligente no grupo central da borda do retângulo delimitador.  
  
-   O bitmap principal que representa o grupo central.  
  
-   Os bitmaps que representa os regulares e realçados marcadores inteligentes de encaixe.  
  
 A ilustração a seguir mostra um exemplo de marcadores inteligentes de encaixe que foram personalizados:  
  
 ![Marcadores personalizados para encaixar smart](../../mfc/reference/media/nextsdmarkerscustom.png "nextsdmarkerscustom")  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CSmartDockingInfo](../../mfc/reference/csmartdockinginfo-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxDockingManager.h  
  
##  <a name="copyto"></a>  CSmartDockingInfo::CopyTo  
 Copia os parâmetros atuais de encaixe inteligentes fornecido [CSmartDockingInfo](../../mfc/reference/csmartdockinginfo-class.md) objeto.  
  
```  
void CopyTo(CSmartDockingInfo& params);
```  
  
### <a name="parameters"></a>Parâmetros  
*params*<br/>
[out] Um objeto do tipo `CSmartDockingInfo` que é preenchida com os parâmetros atuais de encaixe inteligentes.  
  
##  <a name="m_busethemecolorinshading"></a>  CSmartDockingInfo::m_bUseThemeColorInShading  
 Especifica se deve usar a cor do tema atual quando o framework exibe marcadores inteligentes de encaixe.  
  
```  
BOOL m_bUseThemeColorInShading;  
```  
  
### <a name="remarks"></a>Comentários  
 Se for TRUE, os marcadores são desenhados usando a cor do tema atual; Caso contrário, os marcadores são desenhados com a cor azul claro.  
  
 O valor padrão é FALSE.  
  
##  <a name="m_clrbasebackground"></a>  CSmartDockingInfo::m_clrBaseBackground  
 Especifica a cor do plano de fundo de base de marcadores inteligentes de encaixe.  
  
```  
COLORREF m_clrBaseBackground;  
```  
  
##  <a name="m_clrtonedest"></a>  CSmartDockingInfo::m_clrToneDest  
 Especifica a cor que irá substituir `m_clrToneSrc` em bitmaps de marcador de encaixe inteligente.  
  
```  
COLORREF m_clrToneDest;  
```  
  
### <a name="remarks"></a>Comentários  
 Defina esse valor para alterar a cor do marcador bitmaps de forma programática. Por exemplo, se você quiser alterar a cor dos marcadores padrão fornecidos com o framework, defina esse valor para a cor desejada. Por padrão, [CSmartDockingInfo::m_clrToneSrc](#m_clrtonesrc) é definido como RGB (61, 123, 241) (uma cor azulada).  
  
 Para alterar a cor dos marcadores personalizados, você deve especificar `m_clrToneDest` e `m_clrToneSrc`.  
  
##  <a name="m_clrtonesrc"></a>  CSmartDockingInfo::m_clrToneSrc  
 Especifica a cor do smart bitmaps de marcador de encaixe.  
  
```  
COLORREF m_clrToneSrc;  
```  
  
### <a name="remarks"></a>Comentários  
 Defina esse valor somente quando você deseja substituir a cor de um bitmap personalizado com outra cor. Você não precisa definir esse valor se você estiver alterando a cor de um padrão (estrutura fornecida) marcador.  
  
 Use `(COLORREF)-1` para deixar um membro do grupo de encaixe inteligente vazio.  
  
##  <a name="m_clrtransparent"></a>  CSmartDockingInfo::m_clrTransparent  
 Especifica a cor do smart bitmaps de marcador de encaixe quando eles são transparentes.  
  
```  
COLORREF m_clrTransparent;  
```  
  
### <a name="remarks"></a>Comentários  
 Você deve definir esse valor quando você exibe marcadores personalizados e bitmaps personalizados no grupo de encaixe.  
  
##  <a name="m_ncentralgroupoffset"></a>  CSmartDockingInfo::m_nCentralGroupOffset  
 Especifica o deslocamento entre o grupo central de marcadores inteligentes de encaixe e os limites do retângulo de grupo central.  
  
```  
int m_nCentralGroupOffset;  
```  
  
### <a name="remarks"></a>Comentários  
 Especifique esse valor se você quiser alterar o deslocamento padrão entre os limites do grupo central de marcadores inteligentes de encaixe e marcadores personalizados. O deslocamento padrão é 5 pixels.  
  
##  <a name="m_sizetotal"></a>  CSmartDockingInfo::m_sizeTotal  
 Especifica o tamanho total de um retângulo delimitador que inclui todos os marcadores inteligentes de encaixe no grupo central.  
  
```  
CSize m_sizeTotal;  
```  
  
### <a name="remarks"></a>Comentários  
 Definir `m_sizeTotal` para o tamanho do retângulo delimitador do marcador de grupo central. Você deve especificar esse valor se você estiver usando bitmaps personalizados para os marcadores.  
  
##  <a name="m_uimarkerbmpresid"></a>  CSmartDockingInfo::m_uiMarkerBmpResID  
 Define as IDs dos bitmaps que são usados para não realçado personalizados marcadores inteligentes de encaixe do recurso.  
  
```  
UINT m_uiMarkerBmpResID[AFX_SD_MARKERS_NUM];  
```  
  
### <a name="remarks"></a>Comentários  
 Preencha essa matriz com as IDs dos bitmaps que representa os marcadores inteligentes de encaixe do recurso. AFX_SD_MARKERS_NUM atualmente é definido como 5. Você pode preencher a matriz da seguinte maneira:  
  
```cpp
params.m_uiMarkerBmpResID[0] = IDB_MARKER_LEFT;
params.m_uiMarkerBmpResID[1] = IDB_MARKER_RIGHT;
params.m_uiMarkerBmpResID[2] = IDB_MARKER_TOP;
params.m_uiMarkerBmpResID[3] = IDB_MARKER_BOTTOM;
params.m_uiMarkerBmpResID[4] = IDB_MARKER_CENTER;
```
  
##  <a name="m_uimarkerlightbmpresid"></a>  CSmartDockingInfo::m_uiMarkerLightBmpResID  
 Define as IDs dos bitmaps que são usados para realçado personalizados marcadores inteligentes de encaixe do recurso.  
  
```  
UINT m_uiMarkerLightBmpResID[AFX_SD_MARKERS_NUM];  
```  
  
### <a name="remarks"></a>Comentários  
 Preencha essa matriz com as IDs dos bitmaps que representa os realçado marcadores inteligentes de encaixe do recurso. AFX_SD_MARKERS_NUM atualmente é definido como 5. Você pode preencher a matriz da seguinte maneira:  
  
```cpp
params.m_uiMarkerLightBmpResID[0] = IDB_MARKER_LEFT_LIGHT;
params.m_uiMarkerLightBmpResID[1] = IDB_MARKER_RIGHT_LIGHT;
params.m_uiMarkerLightBmpResID[2] = IDB_MARKER_TOP_LIGHT;
params.m_uiMarkerLightBmpResID[3] = IDB_MARKER_BOTTOM_LIGHT;
params.m_uiMarkerLightBmpResID[4] = IDB_MARKER_CENTER_LIGHT;
```
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)
