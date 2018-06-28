---
title: Classe CMFCRibbonUndoButton | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCRibbonUndoButton
- AFXRIBBONUNDOBUTTON/CMFCRibbonUndoButton
- AFXRIBBONUNDOBUTTON/CMFCRibbonUndoButton::CMFCRibbonUndoButton
- AFXRIBBONUNDOBUTTON/CMFCRibbonUndoButton::AddUndoAction
- AFXRIBBONUNDOBUTTON/CMFCRibbonUndoButton::CleanUpUndoList
- AFXRIBBONUNDOBUTTON/CMFCRibbonUndoButton::GetActionNumber
- AFXRIBBONUNDOBUTTON/CMFCRibbonUndoButton::HasMenu
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonUndoButton [MFC], CMFCRibbonUndoButton
- CMFCRibbonUndoButton [MFC], AddUndoAction
- CMFCRibbonUndoButton [MFC], CleanUpUndoList
- CMFCRibbonUndoButton [MFC], GetActionNumber
- CMFCRibbonUndoButton [MFC], HasMenu
ms.assetid: 5c42adf7-871d-4239-901e-47ae7fb816fc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bcddf0f1848bdd75714bd5b931dcf8520e68cf8c
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37041241"
---
# <a name="cmfcribbonundobutton-class"></a>Classe CMFCRibbonUndoButton
O `CMFCRibbonUndoButton` classe implementa um botão de lista suspensa que contém os comandos mais recentes do usuário. Os usuários podem selecionar um ou mais dos comandos mais recentes da lista suspensa para refazer ou desfazê-las.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonUndoButton : public CMFCRibbonGallery  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonUndoButton::CMFCRibbonUndoButton](#cmfcribbonundobutton)|Constrói um novo `CMFCRibbonUndoButton` objeto usando a ID de comando que você especificar, o rótulo de texto e imagens da lista de imagens do objeto pai.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonUndoButton::AddUndoAction](#addundoaction)|Adiciona uma nova ação à lista de ações.|  
|[CMFCRibbonUndoButton::CleanUpUndoList](#cleanupundolist)|Limpa a lista de ação, que é a lista suspensa.|  
|[CMFCRibbonUndoButton::GetActionNumber](#getactionnumber)|Determina o número de itens que um usuário selecionado na lista suspensa.|  
|[CMFCRibbonUndoButton::HasMenu](#hasmenu)|Indica se o objeto contém um menu.|  
  
## <a name="remarks"></a>Comentários  
 O `CMFCRibbonUndoButton` classe usa uma pilha para representar a lista suspensa.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um objeto de `CMFCRibbonUndoButton` classe e adicionar uma nova ação à lista de ações. Este trecho de código é parte do [exemplo Gadgets da faixa de opções](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_RibbonGadgets#2](../../mfc/reference/codesnippet/cpp/cmfcribbonundobutton-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)  
  
 [CMFCRibbonGallery](../../mfc/reference/cmfcribbongallery-class.md)  
  
 [CMFCRibbonUndoButton](../../mfc/reference/cmfcribbonundobutton-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxribbonundobutton.h  
  
##  <a name="addundoaction"></a>  CMFCRibbonUndoButton::AddUndoAction  
 Adiciona uma nova ação à lista de ações.  
  
```  
void AddUndoAction(LPCTSTR lpszLabel);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *lpszLabel*  
 O rótulo de ação que será exibido na lista suspensa.  
  
##  <a name="cleanupundolist"></a>  CMFCRibbonUndoButton::CleanUpUndoList  
 Limpa a lista de ação, que é a lista suspensa.  
  
```  
void CleanUpUndoList();
```  
  
##  <a name="cmfcribbonundobutton"></a>  CMFCRibbonUndoButton::CMFCRibbonUndoButton  
 Constrói um novo `CMFCRibbonUndoButton` objeto usando a ID de comando que você especificar, o rótulo de texto e imagens da lista de imagens do objeto pai.  
  
```  
CMFCRibbonUndoButton(
    UINT nID,  
    LPCTSTR lpszText,  
    int nSmallImageIndex=-1,  
    int nLargeImageIndex=-1);

 
CMFCRibbonUndoButton(
    UINT nID,  
    LPCTSTR lpszText,  
    HICON hIcon);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *nID*  
 Especifica o identificador de comando.  
  
 [in] *lpszText*  
 Especifica o rótulo de texto do botão.  
  
 [in] *nSmallImageIndex*  
 Índice de base zero na lista de imagens do objeto pai para a imagem em miniatura do botão.  
  
 [in] *nLargeImageIndex*  
 Índice de base zero na lista de imagens do objeto pai para a imagem grande do botão.  
  
 [in] *hIcon*  
 Um identificador para um ícone que você pode usar como imagem do botão.  
  
##  <a name="getactionnumber"></a>  CMFCRibbonUndoButton::GetActionNumber  
 Determina o número de itens que um usuário selecionado na lista suspensa.  
  
```  
int GetActionNumber() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens que um usuário selecionado.  
  
##  <a name="hasmenu"></a>  CMFCRibbonUndoButton::HasMenu  
 Indica se o objeto contém um menu.  
  
```  
virtual BOOL HasMenu() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCRibbonGallery](../../mfc/reference/cmfcribbongallery-class.md)   
 [Classe CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)
