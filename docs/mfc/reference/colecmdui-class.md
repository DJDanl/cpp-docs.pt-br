---
title: Classe COleCmdUI | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleCmdUI
- AFXDOCOBJ/COleCmdUI
- AFXDOCOBJ/COleCmdUI::COleCmdUI
- AFXDOCOBJ/COleCmdUI::Enable
- AFXDOCOBJ/COleCmdUI::SetCheck
- AFXDOCOBJ/COleCmdUI::SetText
dev_langs:
- C++
helpviewer_keywords:
- document object server
- COleCmdUI class
- servers [C++], ActiveX documents
- docobject server
- servers [C++], doc objects
- ActiveX documents [C++], document server
ms.assetid: a2d5ce08-6657-45d3-8673-2a9f32d50eec
caps.latest.revision: 21
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
ms.openlocfilehash: 38e7019d7636166262028d955455cee675824f8b
ms.lasthandoff: 02/25/2017

---
# <a name="colecmdui-class"></a>Classe COleCmdUI
Implementa um método para MFC atualizar o estado dos objetos de interface do usuário relacionado para o `IOleCommandTarget`-controlada por recursos de seu aplicativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleCmdUI : public CCmdUI  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleCmdUI::COleCmdUI](#colecmdui)|Constrói um objeto `COleCmdUI`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleCmdUI::Enable](#enable)|Define ou limpa o sinalizador de comando enable.|  
|[COleCmdUI::SetCheck](#setcheck)|Define o estado de uma alternância de ativar/desativar comando.|  
|[COleCmdUI::SetText](#settext)|Retorna uma cadeia de texto nome ou o status de um comando.|  
  
## <a name="remarks"></a>Comentários  
 Em um aplicativo que não está habilitado para DocObjects, quando o usuário exibe um menu no aplicativo, processos MFC **UPDATE_COMMAND_UI** notificações. Cada notificação é fornecida um [CCmdUI](../../mfc/reference/ccmdui-class.md) objeto que pode ser manipulado para refletir o estado de um determinado comando. No entanto, quando seu aplicativo está habilitado para DocObjects, MFC processa **UPDATE_OLE_COMMAND_UI** notificações e atribui `COleCmdUI` objetos.  
  
 `COleCmdUI`permite que um DocObject receber comandos originadas na interface do usuário do seu contêiner (por exemplo, FileNew, abrir, imprimir e assim por diante) e permite que um contêiner para receber comandos originadas na interface do usuário do DocObject. Embora `IDispatch` pode ser usado para enviar os mesmos comandos, `IOleCommandTarget` fornece uma maneira mais simples de consulta e execute porque ele se baseia em um conjunto padrão de comandos, geralmente sem argumentos, e nenhuma informação de tipo está envolvida. `COleCmdUI`pode ser usado para habilitar, atualizar e definir outras propriedades do DocObject comandos de interface do usuário. Quando você deseja invocar o comando, chame [COleServerDoc::OnExecOleCmd](../../mfc/reference/coleserverdoc-class.md#onexecolecmd).  
  
 Para obter mais informações sobre DocObjects, consulte [CDocObjectServer](../../mfc/reference/cdocobjectserver-class.md) e [CDocObjectServerItem](../../mfc/reference/cdocobjectserveritem-class.md). Consulte também [Internet primeiras etapas: documentos ativos](../../mfc/active-documents-on-the-internet.md) e [documentos ativos](../../mfc/active-documents-on-the-internet.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CCmdUI](../../mfc/reference/ccmdui-class.md)  
  
 `COleCmdUI`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdocobj.h  
  
##  <a name="colecmdui"></a>COleCmdUI::COleCmdUI  
 Constrói uma `COleCmdUI` objeto associado a um comando específico da interface do usuário.  
  
```  
COleCmdUI(
    OLECMD* rgCmds,  
    ULONG cCmds,  
    const GUID* m_pGroup);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rgCmds`  
 Uma lista de comandos com suporte associado com o GUID especificado. O **OLECMD** estrutura associa comandos com sinalizadores de comando.  
  
 *cCmds*  
 A contagem de comandos no `rgCmds`.  
  
 `pGroup`  
 Um ponteiro para um GUID que identifica um conjunto de comandos.  
  
### <a name="remarks"></a>Comentários  
 O `COleCmdUI` objeto fornece uma interface programática para atualizar objetos de interface do usuário DocObject como itens de menu ou botões da barra de controle. Os objetos de interface do usuário podem ser habilitados, desabilitados, marcados e desmarcados por meio de `COleCmdUI` objeto.  
  
##  <a name="enable"></a>COleCmdUI::Enable  
 Chame essa função para definir o sinalizador de comando da `COleCmdUI` objeto **OLECOMDF_ENABLED**, que informa a interface de comando está disponível e habilitado, ou limpar o sinalizador de comando.  
  
```  
virtual void Enable(BOOL bOn);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bOn`  
 Indica se o comando associado a `COleCmdUI` objeto deve ser habilitado ou desabilitado. NonZero permite que o comando. 0 desabilita o comando.  
  
##  <a name="setcheck"></a>COleCmdUI::SetCheck  
 Chame essa função para definir o estado de uma alternância de ativar/desativar comando.  
  
```  
virtual void SetCheck(int nCheck);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nCheck`  
 Um valor que determina o estado para definir uma alternância de ativar/desativar comando. Os valores são:  
  
|Valor|Descrição|  
|-----------|-----------------|  
|**1**|Define o comando para ativado.|  
|**2**|Define o comando para indeterminado; o estado não pode ser determinado porque o atributo desse comando no dentro e fora de estados da seleção relevante.|  
|qualquer outro valor|Define o comando a ser desativado.|  
  
##  <a name="settext"></a>COleCmdUI::SetText  
 Chame essa função para retornar uma cadeia de texto nome ou o status de um comando.  
  
```  
virtual void SetText(LPCTSTR lpszText);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszText`  
 Um ponteiro para o texto a ser usado com o comando.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCmdUI](../../mfc/reference/ccmdui-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)




