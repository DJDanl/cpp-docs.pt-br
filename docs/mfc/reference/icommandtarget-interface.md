---
title: Interface ICommandTarget | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- ICommandTarget
- AFXWINFORMS/ICommandTarget
- AFXWINFORMS/ICommandTarget::Initialize
dev_langs:
- C++
helpviewer_keywords:
- ICommandTarget interface [MFC]
ms.assetid: dd9927f6-3479-4e7c-8ef9-13206cf901f3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b32112fbad516b2550da0cc48cb6c287583d396c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="icommandtarget-interface"></a>Interface ICommandTarget
Fornece um controle de usuário com uma interface para receber comandos de um objeto de origem de comando.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
interface class ICommandTarget  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[ICommandTarget::Initialize](#initialize)|Inicializa o objeto de destino do comando.|  
  
## <a name="remarks"></a>Comentários  
 Quando você hospeda um controle de usuário em uma exibição MFC, [CWinFormsView](../../mfc/reference/cwinformsview-class.md) comandos de rotas e atualização de comando mensagens de interface do usuário para o controle de usuário para permitir que ele trate comandos MFC (por exemplo, itens de menu do quadro e botões de barra de ferramentas). Implementando `ICommandTarget`, você concede o controle de usuário, uma referência para o [ICommandSource](../../mfc/reference/icommandsource-interface.md) objeto.  
  
 Consulte [como: Adicionar roteamento de comando para o controle Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) para obter um exemplo de como usar `ICommandTarget`.  
  
 Para obter mais informações sobre como usar formulários do Windows, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwinforms.h (definido no assembly atlmfc\lib\mfcmifc80.dll)  
  
##  <a name="initialize"></a> ICommandTarget::Initialize  
 Inicializa o objeto de destino do comando.  
  
```  
void Initialize(ICommandSource^ cmdSource);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `cmdSource`  
 Um identificador para o objeto de origem de comando.  
  
### <a name="remarks"></a>Comentários  
 Quando você hospeda um controle de usuário em uma exibição MFC, CWinFormsView roteia comandos e mensagens de interface do usuário do comando de atualização para o controle de usuário para permitir que ele lidar com comandos do MFC.  
  
 Esse método inicializa o objeto de destino do comando e a associa a cmdSource de objeto de origem de comando especificado. Ele deve ser chamado na implementação de classe do controle do usuário. Na inicialização, você deve registrar manipuladores de comandos com o objeto de origem de comando por chamada ICommandSource::AddCommandHandler na implementação de inicialização. Consulte como: Adicionar roteamento de comando para o controle dos Windows Forms para obter um exemplo de como usar a inicialização para fazer isso.  
  
## <a name="see-also"></a>Consulte também  
 [Como: adicionar comandos de controle de formulários do roteamento para o Windows](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md)   
 [Interface ICommandSource](../../mfc/reference/icommandsource-interface.md)



