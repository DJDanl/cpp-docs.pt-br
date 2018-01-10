---
title: Classe CMFCRibbonQuickAccessToolBarDefaultState | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCRibbonQuickAccessToolBarDefaultState
- AFXRIBBONQUICKACCESSTOOLBAR/CMFCRibbonQuickAccessToolBarDefaultState
- AFXRIBBONQUICKACCESSTOOLBAR/CMFCRibbonQuickAccessToolBarDefaultState::CMFCRibbonQuickAccessToolBarDefaultState
- AFXRIBBONQUICKACCESSTOOLBAR/CMFCRibbonQuickAccessToolBarDefaultState::AddCommand
- AFXRIBBONQUICKACCESSTOOLBAR/CMFCRibbonQuickAccessToolBarDefaultState::CopyFrom
- AFXRIBBONQUICKACCESSTOOLBAR/CMFCRibbonQuickAccessToolBarDefaultState::RemoveAll
dev_langs: C++
helpviewer_keywords:
- CMFCRibbonQuickAccessToolBarDefaultState [MFC], CMFCRibbonQuickAccessToolBarDefaultState
- CMFCRibbonQuickAccessToolBarDefaultState [MFC], AddCommand
- CMFCRibbonQuickAccessToolBarDefaultState [MFC], CopyFrom
- CMFCRibbonQuickAccessToolBarDefaultState [MFC], RemoveAll
ms.assetid: eca99200-b87b-47ba-b2e8-2f3f2444b176
caps.latest.revision: "28"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2e60157ee70ea5df3835d817972a7bcb0dfe2db0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmfcribbonquickaccesstoolbardefaultstate-class"></a>Classe CMFCRibbonQuickAccessToolBarDefaultState
Uma classe auxiliar que gerencia o estado padrão para a barra de ferramentas de acesso rápido que é posicionado na barra de faixa de opções ( [classe CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md)).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonQuickAccessToolBarDefaultState  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonQuickAccessToolBarDefaultState::CMFCRibbonQuickAccessToolBarDefaultState](#cmfcribbonquickaccesstoolbardefaultstate)|Constrói um objeto `CMFCRibbonQuickAccessToolbarDefaultState`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonQuickAccessToolBarDefaultState::AddCommand](#addcommand)|Adiciona um comando para o estado padrão para a barra de ferramentas de acesso rápido. Isso não altera a barra de ferramentas em si.|  
|[CMFCRibbonQuickAccessToolBarDefaultState::CopyFrom](#copyfrom)|Copia as propriedades de uma barra de ferramentas de acesso rápido para outro.|  
|[CMFCRibbonQuickAccessToolBarDefaultState::RemoveAll](#removeall)|Remove todos os comandos da barra de ferramentas de acesso rápido. Isso não altera a barra de ferramentas em si.|  
  
## <a name="remarks"></a>Comentários  
 Depois de criar a barra de ferramentas de acesso rápido em seu aplicativo, é recomendável que você defina o estado padrão chamando [CMFCRibbonBar::SetQuickAccessDefaultState](../../mfc/reference/cmfcribbonbar-class.md#setquickaccessdefaultstate). Esse estado padrão é restaurado quando um usuário clica o **redefinir** botão o **personalizar** página do seu aplicativo **opções** caixa de diálogo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CMFCRibbonQuickAccessToolBarDefaultState](../../mfc/reference/cmfcribbonquickaccesstoolbardefaultstate-class.md)  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um objeto de `CMFCRibbonQuickAccessToolbarDefaultState` classe e como adicionar um comando para o estado padrão para a barra de ferramentas de acesso rápido.  
  
 [!code-cpp[NVC_MFC_RibbonApp#21](../../mfc/reference/codesnippet/cpp/cmfcribbonquickaccesstoolbardefaultstate-class_1.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxribbonquickaccesstoolbar.h  
  
##  <a name="addcommand"></a>CMFCRibbonQuickAccessToolBarDefaultState::AddCommand  
 Adiciona um comando para o estado padrão para a barra de ferramentas de acesso rápido.  
  
```  
void AddCommand(
    UINT uiCmd,  
    BOOL bIsVisible=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `[in] uiCmd`  
 Especifica a ID de comando.  
  
 `[in] bIsVisible`  
 Define a visibilidade do comando quando a barra de ferramentas de acesso rápido está no estado padrão.  
  
### <a name="remarks"></a>Comentários  
 Adicionar um comando para o CMFCRibbonQuickAccessToolBarDefaultState realiza três resultados. Primeiro, cada comando adicionado está listado na lista suspensa à direita da barra de ferramentas de acesso rápido. Dessa maneira, um usuário pode adicionar ou remover facilmente comando da barra de ferramentas de acesso rápido. Em segundo lugar, a barra de ferramentas de acesso rápido é redefinida para mostrar somente os comandos que são listados como visível no estado padrão quando o usuário clica o **redefinir** no botão de **personalizar** caixa de diálogo. Terceiro, se você não tiver chamado [CMFCRibbonBar::SetQuickAccessCommands](../../mfc/reference/cmfcribbonbar-class.md#setquickaccesscommands), a barra de ferramentas de acesso rápido usa os comandos visíveis na lista como comandos visíveis padrão na primeira vez que um usuário executa o aplicativo. Depois de ter adicionado todos os comandos que você deseja, chame [CMFCRibbonBar::SetQuickAccessDefaultState](../../mfc/reference/cmfcribbonbar-class.md#setquickaccessdefaultstate) definir essa instância como o estado padrão para a barra de ferramentas de acesso rápido da barra de faixa de opções.  
  
##  <a name="copyfrom"></a>CMFCRibbonQuickAccessToolBarDefaultState::CopyFrom  
 Copia as propriedades de uma barra de ferramentas de acesso rápido para outro.  
  
```  
void CopyFrom(const CMFCRibbonQuickAccessToolBarDefaultState& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `src`  
 Uma referência à fonte de `CMFCRibbonQuickAccessToolBarDefaultState` objeto do qual copiar.  
  
### <a name="remarks"></a>Comentários  
 Esse método copia cada comando da origem do `CMFCRibbonQuickAccessToolBarDefaultState` objeto para esse objeto usando o [CMFCRibbonQuickAccessToolBarDefaultState::AddCommand](#addcommand) método.  
  
##  <a name="cmfcribbonquickaccesstoolbardefaultstate"></a>CMFCRibbonQuickAccessToolBarDefaultState::CMFCRibbonQuickAccessToolBarDefaultState  
 Constrói o objeto de estado de padrão de ferramentas de acesso rápido.  
  
```  
CMFCRibbonQuickAccessToolBarDefaultState();
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, a lista de comandos que a nova instância do [CMFRibbonQuickAccessToolBarDefaultState](../../mfc/reference/cmfcribbonquickaccesstoolbardefaultstate-class.md) contém está vazio.  
  
##  <a name="removeall"></a>CMFCRibbonQuickAccessToolBarDefaultState::RemoveAll  
 Limpa a lista de comandos padrão na barra de ferramentas de acesso rápido.  
  
```  
void RemoveAll();
```  
  
### <a name="remarks"></a>Comentários  
 Esta função remove essa instância todos os comandos que as chamadas anteriores para [CMFCRibbonQuickAccessToolBarDefaultState::AddCommand](#addcommand) adicionado.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md)
