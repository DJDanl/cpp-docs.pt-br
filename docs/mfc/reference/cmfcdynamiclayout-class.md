---
title: Classe CMFCDynamicLayout | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCDynamicLayout
- AFXLAYOUT/CMFCDynamicLayout
- AFXLAYOUT/CMFCDynamicLayout::AddItem
- AFXLAYOUT/CMFCDynamicLayout::Adjust
- AFXLAYOUT/CMFCDynamicLayout::Create
- AFXLAYOUT/CMFCDynamicLayout::GetHostWnd
- AFXLAYOUT/CMFCDynamicLayout::GetMinSize
- AFXLAYOUT/CMFCDynamicLayout::GetWindowRect
- AFXLAYOUT/CMFCDynamicLayout::HasItem
- AFXLAYOUT/CMFCDynamicLayout::IsEmpty
- AFXLAYOUT/CMFCDynamicLayout::LoadResource
- AFXLAYOUT/CMFCDynamicLayout::SetMinSize
dev_langs: C++
ms.assetid: c2df2976-f049-47fc-9cf0-abe3e01948bc
caps.latest.revision: "16"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 6604ada6dc4d322011a835c03731f6a48be472f2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmfcdynamiclayout-class"></a>Classe CMFCDynamicLayout
Especifica como os controles em uma janela são movidos e redimensionados uma vez que o usuário redimensionar a janela.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCDynamicLayout : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCDynamicLayout::CMFCDynamicLayout`|Constrói um objeto `CMFCDynamicLayout`.|  
|`CMFCDynamicLayout::~CMFCDynamicLayout`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCDynamicLayout::AddItem](#additem)|Adiciona uma janela filho, geralmente, um controle, à lista de janelas que são controlados pelo Gerenciador de layout dinâmico.|  
|[CMFCDynamicLayout::Adjust](#adjust)|Adiciona uma janela filho, geralmente, um controle, à lista de janelas que são controlados pelo Gerenciador de layout dinâmico.|  
|[CMFCDynamicLayout::Create](#create)|Armazena e valida a janela do host.|  
|[CMFCDynamicLayout::GetHostWnd](#gethostwnd)|Retorna um ponteiro para uma janela do host.|  
|[CMFCDynamicLayout::GetMinSize](#getminsize)|Retorna o tamanho da janela abaixo do qual o layout não é ajustado.|  
|[CMFCDynamicLayout::GetWindowRect](#getwindowrect)|Recupera o retângulo para a área de cliente atual da janela.|  
|[CMFCDynamicLayout::HasItem](#hasitem)|Verifica se um controle filho foi adicionado ao layout dinâmico.|  
|[CMFCDynamicLayout::IsEmpty](#isempty)|Verifica se um layout dinâmico tem sem janelas filho adicionadas.|  
|[CMFCDynamicLayout::LoadResource](#loadresource)|Lê o layout dinâmico do recurso AFX_DIALOG_LAYOUT e, em seguida, aplica o layout para a janela do host.|  
|estático [CMFCDynamicLayout::MoveHorizontal](#movehorizontal)|Obtém um [MoveSettings](#movesettings_structure) valor que define o quanto um controle filho é movido horizontalmente quando o usuário o redimensiona a janela de hospedagem.|  
|estático [CMFCDynamicLayout::MoveHorizontalAndVertical](#movehorizontalandvertical)|Obtém um [MoveSettings](#movesettings_structure) valor que define o quanto um controle filho é movido horizontalmente quando o usuário o redimensiona a janela de hospedagem.|  
|estático [CMFCDynamicLayout::MoveNone](#movenone)|Obtém um [MoveSettings](#movesettings_structure) valor que não representa nenhum movimento, vertical ou horizontal, para um controle filho.|  
|estático [CMFCDynamicLayout::MoveVertical](#movevertical)|Obtém um [MoveSettings](#movesettings_structure) valor que define o quanto um controle filho é movido verticalmente quando o usuário o redimensiona a janela de hospedagem.|  
|[CMFCDynamicLayout::SetMinSize](#setminsize)|Define o tamanho da janela abaixo do qual o layout não é ajustado.|  
|estático [CMFCDynamicLayout::SizeHorizontal](#sizehorizontal)|Obtém um [SizeSettings](#sizesettings_structure) valor que define quanto um controle filho é redimensionado horizontalmente quando o usuário o redimensiona a janela de hospedagem.|  
|estático [CMFCDynamicLayout::SizeHorizontalAndVertical](#sizehorizontalandvertical)|Obtém um [SizeSettings](#sizesettings_structure) valor que define quanto um controle filho é redimensionado horizontalmente quando o usuário o redimensiona a janela de hospedagem.|  
|estático [CMFCDynamicLayout::SizeNone](#sizenone)|Obtém um [SizeSettings](#sizesettings_structure) valor que não representa a nenhuma alteração no tamanho de um controle filho.|  
|estático [CMFCDynamicLayout::SizeVertical](#sizevertical)|Obtém um [SizeSettings](#sizesettings_structure) valor que define quanto um controle filho é redimensionado verticalmente quando o usuário o redimensiona a janela de hospedagem.|  
  
## <a name="nested-types"></a>Tipos aninhados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Estrutura cmfcdynamiclayout:: Movesettings](#movesettings_structure)|Encapsula mover dados para controles em um layout dinâmico.|  
|[Estrutura CMFCDynamicLayout::SizeSettings](#sizesettings_structure)|Encapsula os dados de alteração de tamanho para controles em um layout dinâmico.|  
  
## <a name="remarks"></a>Comentários  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCDynamicLayout](../../mfc/reference/cmfctoolbarbutton-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxlayout.h  
  
##  <a name="additem"></a>CMFCDynamicLayout::AddItem  
 Adiciona uma janela filho, geralmente, um controle, à lista de janelas que são controlados pelo Gerenciador de layout dinâmico.  
  
```  
BOOL AddItem(
    HWND hwnd,
    MoveSettings moveSettings SizeSettings sizeSettings);

 
BOOL AddItem(
    int nID,
    MoveSettings moveSettings SizeSettings sizeSettings);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hwnd`  
 O identificador para a janela para adicionar.  
  
 `nID`  
 A identificação do controle filho.  
  
 `moveSettings`  
 Uma estrutura que descreve como o controle deve ser movido como as alterações de tamanho de janela.  
  
 `sizeSettings`  
 Uma estrutura que descreve como o controle deve ser redimensionado como as alterações de tamanho de janela.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o item foi adicionado com êxito; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 A posição e tamanho de um controle filho é alterado dinamicamente quando uma janela de hospedagem está sendo redimensionada.  
  
##  <a name="adjust"></a>CMFCDynamicLayout::Adjust  
 Adiciona uma janela filho, geralmente, um controle, à lista de janelas que são controlados pelo Gerenciador de layout dinâmico.  
  
```  
void Adjust();
```  
  
### <a name="remarks"></a>Comentários  
 A posição e tamanho de um controle filho é alterado dinamicamente quando uma janela de hospedagem está sendo redimensionada.  
  
##  <a name="create"></a>CMFCDynamicLayout::Create  
 Armazena e valida a janela do host.  
  
```  
BOOL Create(CWnd* pHostWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 pHostWnd  
 Um ponteiro para a janela do host.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a criação bem-sucedida; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="gethostwnd"></a>CMFCDynamicLayout::GetHostWnd  
 Retorna um ponteiro para uma janela do host.  
  
```  
CWnd* GetHostWnd();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a janela do host.  
  
### <a name="remarks"></a>Comentários  
 Por padrão a todas as posições de controle filho recalculadas em relação a esta janela.  
  
##  <a name="getminsize"></a>CMFCDynamicLayout::GetMinSize  
 Retorna o tamanho da janela abaixo do qual o layout não é ajustado.  
  
```  
CSize GetMinSize();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho da janela abaixo do qual o layout não é ajustado.  
  
### <a name="remarks"></a>Comentários  
 A posição e tamanho de um controle filho é alterado dinamicamente, quando uma janela de hospedagem está sendo redimensionada, mas não há um tamanho mínimo abaixo do qual o layout não é ajustado. O usuário pode redimensionar a janela para um tamanho menor, mas as partes da janela, em seguida, ficam ocultos na exibição.  
  
##  <a name="getwindowrect"></a>CMFCDynamicLayout::GetWindowRect  
 Recupera o retângulo para a área de cliente atual da janela.  
  
```  
void GetHostWndRect(CRect& rect,);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rect`  
 Depois que a função retornar, este parâmetro contém o retângulo delimitador da área de layout. Este é um parâmetro de saída; o valor de entrada é substituído.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="hasitem"></a>CMFCDynamicLayout::HasItem  
 Verifica se um controle filho foi adicionado ao layout dinâmico.  
  
```  
BOOL HasItem(HWND hwnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hwnd`  
 O identificador de janela para o controle.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o layout já tem este item; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="isempty"></a>CMFCDynamicLayout::IsEmpty  
 Verifica se um layout dinâmico tem sem janelas filho adicionadas.  
  
```  
BOOL IsEmpty();
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o layout não tem nenhum item; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="loadresource"></a>CMFCDynamicLayout::LoadResource  
 Lê o layout dinâmico do recurso AFX_DIALOG_LAYOUT e, em seguida, aplica o layout para a janela do host.  
  
```  
static BOOL LoadResource(CWnd* pHostWnd,
    LPVOID lpResource,
    DWORD dwSize);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pHostWnd`  
 Um ponteiro para a janela do host.  
  
 `lpResource`  
 Um ponteiro para o buffer que contém o recurso AFX_DIALOG_LAYOUT.  
  
 `dwSize`  
 O tamanho do buffer em bytes.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o recurso é carregado e aplicado para a janela host; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="movehorizontal"></a>CMFCDynamicLayout::MoveHorizontal  
 Obtém um [MoveSettings](#movesettings_structure) valor que define o quanto um controle filho é movido horizontalmente quando o usuário o redimensiona a janela de hospedagem.  
  
```  
static MoveSettings MoveHorizontal(int nRatio);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nRatio`  
 Define como uma porcentagem quanto um controle filho é movido horizontalmente quando o usuário o redimensiona a janela do host.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [MoveSettings](#movesettings_structure) valor que encapsula a solicitação Mover taxa.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="movehorizontalandvertical"></a>CMFCDynamicLayout::MoveHorizontalAndVertical  
 Obtém um [MoveSettings](#movesettings_structure) valor que define o quanto um controle filho é movido horizontalmente quando o usuário o redimensiona a janela de hospedagem.  
  
```  
static MoveSettings MoveHorizontalAndVertical(int nXRatio int nYRatio);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nXRatio`  
 Define como uma porcentagem quanto um controle filho é movido horizontalmente quando o usuário o redimensiona a janela do host.  
  
 `nYRatio`  
 Define como uma porcentagem quanto um controle filho é movido verticalmente quando o usuário o redimensiona a janela do host.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [MoveSettings](#movesettings_structure) valor que encapsula a solicitação Mover taxa.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="movenone"></a>CMFCDynamicLayout::MoveNone  
 Obtém um [MoveSettings](#movesettings_structure) valor que não representa nenhum movimento, vertical ou horizontal, para um controle filho.  
  
```  
static MoveSettings MoveNone();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [MoveSettings](#movesettings_structure) valor que corrige o controle no local, para que ele não é movidos como o usuário o redimensiona a janela do host.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="movesettings_structure"></a>Estrutura cmfcdynamiclayout:: Movesettings  
 Encapsula mover dados para controles em um layout dinâmico.  
  
```  
struct CMFCDynamicLayout::MoveSettings;  
```  
  
### <a name="remarks"></a>Comentários  
 Esta é uma classe aninhada dentro de `CMFCDynamicLayout`.  

## <a name="cmfcdynamiclayoutmovesettingsishorizontal"></a>CMFCDynamicLayout::MoveSettings::IsHorizontal
Verifique se mover dados especificam um movimento horizontal diferente de zero.  
  

```  
BOOL IsHorizontal() const 
```  
  
## <a name="return-value"></a>Valor de retorno  
 TRUE se o `MoveSettings` objeto Especifica uma movimentação horizontal diferente de zero.  

 ## <a name="cmfcdynamiclayoutmovesettingsisnone"></a>CMFCDynamicLayout::MoveSettings::IsNone
 Verifique se os dados de movimentação não especificam nenhuma movimentação.  
  
```  
BOOL IsNone() const 
```  
  
## <a name="return-value"></a>Valor de retorno  
 TRUE se o `MoveSettings` objeto não especifica nenhuma movimentação.  

## <a name="cmfcdynamiclayoutmovesettingsisvertical"></a>CMFCDynamicLayout::MoveSettings::IsVertical
  Verifique se mover dados especificam um movimento vertical diferente de zero.  
  
```  
BOOL IsVertical() const 
```  
  
## <a name="return-value"></a>Valor de retorno  
 TRUE se o `MoveSettings` objeto Especifica um movimento vertical diferente de zero.  

##  <a name="movevertical"></a>CMFCDynamicLayout::MoveVertical  
 Obtém um [MoveSettings](#movesettings_structure) valor que define o quanto um controle filho é movido verticalmente quando o usuário o redimensiona a janela de hospedagem.  
  
```  
static MoveSettings MoveVertical(int nRatio);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nRatio`  
 Define como uma porcentagem quanto um controle filho é movido verticalmente quando o usuário o redimensiona a janela do host.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [MoveSettings](#movesettings_structure) valor que encapsula a solicitação Mover taxa.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setminsize"></a>CMFCDynamicLayout::SetMinSize  
 Define o tamanho da janela abaixo do qual o layout não é ajustado.  
  
```  
void SetMinSize(const CSize& size);
```  
  
### <a name="parameters"></a>Parâmetros  
 `size`  
 O tamanho desejado abaixo do qual o layout não é ajustado.  
  
### <a name="remarks"></a>Comentários  
 A posição e tamanho de um controle filho é alterado dinamicamente, quando uma janela de hospedagem está sendo redimensionada, mas não há um tamanho mínimo abaixo do qual o layout não é ajustado. O usuário pode redimensionar a janela para um tamanho menor, mas as partes da janela, em seguida, ficam ocultos na exibição.  
  
##  <a name="sizehorizontal"></a>CMFCDynamicLayout::SizeHorizontal  
 Obtém um [SizeSettings](#sizesettings_structure) valor que define quanto um controle filho é redimensionado horizontalmente quando o usuário o redimensiona a janela de hospedagem.  
  
```  
static SizeSettings SizeHorizontal(int nRatio);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nRatio`  
 Define como uma porcentagem quanto um controle filho é redimensionado horizontalmente quando o usuário o redimensiona a janela do host.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [SizeSettings](#sizesettings_structure) valor que encapsula a proporção de tamanho solicitado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="sizehorizontalandvertical"></a>CMFCDynamicLayout::SizeHorizontalAndVertical  
 Obtém um [SizeSettings](#sizesettings_structure) valor que define quanto um controle filho é redimensionado horizontalmente quando o usuário o redimensiona a janela de hospedagem.  
  
```  
static SizeSettings SizeHorizontalAndVertical(int nXRatio int nYRatio);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nXRatio`  
 Define como uma porcentagem quanto um controle filho é redimensionado horizontalmente quando o usuário o redimensiona a janela do host.  
  
 `nYRatio`  
 Define como uma porcentagem quanto um controle filho é redimensionado verticalmente quando o usuário o redimensiona a janela do host.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [SizeSettings](#sizesettings_structure) valor que encapsula a proporção de tamanho solicitado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="sizenone"></a>CMFCDynamicLayout::SizeNone  
 Obtém um [SizeSettings](#sizesettings_structure) valor que não representa a nenhuma alteração no tamanho de um controle filho.  
  
```  
static SizeSettings SizeNone();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [SizeSettings](#sizesettings_structure) valor que corrige o controle em um determinado tamanho, para que isso não altera o tamanho, como o usuário redimensiona a janela do host.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="sizesettings_structure"></a>Estrutura CMFCDynamicLayout::SizeSettings  
 Encapsula os dados de alteração de tamanho para controles em um layout dinâmico.  
  
```  
struct CMFCDynamicLayout::SizeSettings;  
```  
  
### <a name="remarks"></a>Comentários  
 Esta é uma classe aninhada dentro de `CMFCDynamicLayout`.  

## <a name="cmfcdynamiclayoutsizesettingsishorizontal"></a>CMFCDynamicLayout::SizeSettings::IsHorizontal
Verifica se os dados de redimensionamento especificam um redimensionamento horizontal diferente de zero.  
  
```  
BOOL IsHorizontal() const 
```  
  
## <a name="return-value"></a>Valor de retorno  
 TRUE se o `SizeSettings` objeto Especifica um redimensionamento horizontal diferente de zero. 

## <a name="cmfcdynamiclayoutsizesettingsisnone"></a>CMFCDynamicLayout::SizeSettings::IsNone
Verifica se os dados de redimensionamento especificam sem redimensionamento.  
  
```  
BOOL IsNone() const 
```  
  
## <a name="return-value"></a>Valor de retorno  
 TRUE se o `SizeSettings` objeto especifica sem redimensionamento.  

## <a name="cmfcdynamiclayoutsizesettingsisvertical"></a>CMFCDynamicLayout::SizeSettings::IsVertical
Verifica se os dados de redimensionamento especificam um redimensionamento vertical diferente de zero.  
  
```  
BOOL IsVertical() const 
```  
  
## <a name="return-value"></a>Valor de retorno  
 TRUE se o `SizeSettings` objeto Especifica um redimensionamento vertical diferente de zero.  

##  <a name="sizevertical"></a>CMFCDynamicLayout::SizeVertical  
 Obtém um [SizeSettings](#sizesettings_structure) valor que define quanto um controle filho é redimensionado verticalmente quando o usuário o redimensiona a janela de hospedagem.  
  
```  
static SizeSettings SizeVertical(int nRatio);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nRatio`  
 Define como uma porcentagem quanto um controle filho é redimensionado verticalmente quando o usuário o redimensiona a janela do host.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [SizeSettings](#sizesettings_structure) valor que encapsula a proporção de tamanho solicitado.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)
