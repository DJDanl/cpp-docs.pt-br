---
title: "Interface ICommandTarget | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "ICommandTarget"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Interface ICommandTarget"
ms.assetid: dd9927f6-3479-4e7c-8ef9-13206cf901f3
caps.latest.revision: 27
caps.handback.revision: 27
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Interface ICommandTarget
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece um controle de usuário com uma interface para receber comandos de um objeto de origem do comando.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
interface class ICommandTarget  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[ICommandTarget::Initialize](#icommandtarget__initialize)|Inicializa o objeto de destino de comando.|  
  
## <a name="remarks"></a>Comentários  
 Quando você hospeda um controle de usuário em uma exibição MFC, [CWinFormsView](../../mfc/reference/cwinformsview-class.md) comandos de rotas e atualização de comando mensagens de interface do Usuário para o controle de usuário para permitir que ele manipule comandos MFC (por exemplo, itens de menu do quadro e botões de barra de ferramentas). Implementando `ICommandTarget`, você dá o controle de usuário uma referência para o [ICommandSource](../../mfc/reference/icommandsource-interface.md) objeto.  
  
 Consulte [como: Adicionar roteamento de comando para o controle Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) para obter um exemplo de como usar `ICommandTarget`.  
  
 Para obter mais informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwinforms.h (definido no assembly atlmfc\lib\mfcmifc80.dll)  
  
##  <a name="a-nameicommandtargetinitializea-icommandtargetinitialize"></a><a name="icommandtarget__initialize"></a> ICommandTarget::Initialize  
 Inicializa o objeto de destino de comando.  
  
```  
void Initialize(ICommandSource^ cmdSource);

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `cmdSource`  
 Um identificador para o objeto de origem do comando.  
  
### <a name="remarks"></a>Comentários  
 Quando você hospeda um controle de usuário em uma exibição MFC, CWinFormsView encaminha comandos e as mensagens UI de comando de atualização para o controle de usuário para permitir que lidar com comandos do MFC.  
  
 Esse método inicializa o objeto de destino de comando e associa o cmdSource de objeto de origem do comando especificado. Ele deve ser chamado na implementação de classe do controle de usuário. Na inicialização, você deve registrar manipuladores de comandos com o objeto de origem de comando por chamada ICommandSource::AddCommandHandler na implementação de inicialização. Consulte como: Adicionar roteamento de comando para o controle Windows Forms para obter um exemplo de como usar a inicialização para fazer isso.  
  
## <a name="see-also"></a>Consulte também  
 [Como: Adicionar comando de controle de formulários do roteamento do Windows](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md)   
 [Interface ICommandSource](../../mfc/reference/icommandsource-interface.md)



