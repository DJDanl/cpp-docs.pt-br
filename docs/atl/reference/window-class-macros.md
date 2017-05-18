---
title: Macros de classe de janela | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
ms.assetid: ce18681a-2bab-4453-9895-0f3ea47c2b24
caps.latest.revision: 16
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
ms.sourcegitcommit: 8cdedc5cfac9d49df812ae6fcfcc548201b1edb5
ms.openlocfilehash: f32926b6efd4ffb9c0541c0574a479c13dac01df
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="window-class-macros"></a>Macros de classe de janela
Essas macros definem utilitários de classe de janela.  
  
|||  
|-|-|  
|[DECLARE_WND_CLASS](#declare_wnd_class)|Permite que você especifique o nome de uma nova classe de janela.| 
|[DECLARE_WND_CLASS2](#declare_wnd_class2)|(2017 do visual Studio) Permite que você especifique o nome de uma nova classe de janela e da classe delimitadora cujo procedimento de janela usará a nova classe.| 
|[DECLARE_WND_SUPERCLASS](#declare_wnd_superclass)|Permite que você especifique o nome de uma classe de janela existente no qual uma nova classe de janela será baseada.|  
|[DECLARE_WND_CLASS_EX](#declare_wnd_class_ex)|Permite que você especifique os parâmetros de uma classe.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  
   
##  <a name="declare_wnd_class"></a>DECLARE_WND_CLASS  
 Permite que você especifique o nome de uma nova classe de janela. Coloca essa macro na classe de controle de um controle ActiveX ATL.  
  
```
DECLARE_WND_CLASS( WndClassName )
```  
  
### <a name="parameters"></a>Parâmetros  
 `WndClassName`  
 [in] O nome da nova classe de janela. Se **nulo**, ATL gerará um nome de classe de janela.  
  
### <a name="remarks"></a>Comentários  
 Se você estiver usando a opção /permissive-compiler, DECLARE_WND_CLASS causará um erro do compilador; Use DECLARE_WND_CLASS2.
 
 DECLARE_WND_CLASS permite que você especifique o nome de uma nova classe de janela cujas informações serão gerenciadas pelo [CWndClassInfo](cwndclassinfo-class.md). `DECLARE_WND_CLASS`Define a nova classe de janela, Implementando a função estática a seguir:  
  
 [!code-cpp[NVC_ATL_Windowing&#127;](../../atl/codesnippet/cpp/window-class-macros_1.cpp)]  
  
 `DECLARE_WND_CLASS`Especifica os seguintes estilos para a nova janela:  
  
-   CS_HREDRAW  
  
-   CS_VREDRAW  
  
-   CS_DBLCLKS  
  
 `DECLARE_WND_CLASS`também especifica a cor de plano de fundo da janela padrão. Use o [DECLARE_WND_CLASS_EX](#declare_wnd_class_ex) macro para fornecer seus próprios estilos e cores de plano de fundo.  
  
 [CWindowImpl](cwindowimpl-class.md) usa o `DECLARE_WND_CLASS` macro para criar uma janela com base em uma nova classe de janela. Para substituir esse comportamento, use o [DECLARE_WND_SUPERCLASS](#declare_wnd_superclass) macro, ou fornecer sua própria implementação do [GetWndClassInfo](cwindowimpl-class.md#getwndclassinfo) função.  

  
 Para obter mais informações sobre como usar o windows em ATL, consulte o artigo [Classes de janela ATL](../../atl/atl-window-classes.md).  

##  <a name="declare_wnd_class2"></a>DECLARE_WND_CLASS2  
 (2017 do visual Studio) Semelhante ao DECLARE_WND_CLASS, mas com um parâmetro extra que evita um erro de nome dependente ao compilar com o /permissive-option.
  
```
DECLARE_WND_CLASS2( WndClassName, EnclosingClass )
```  
  
### <a name="parameters"></a>Parâmetros  
 `WndClassName`  
 [in] O nome da nova classe de janela. Se **nulo**, ATL gerará um nome de classe de janela. 

 `EnclosingClass`  
 [in] O nome da classe de janela que inclui a nova classe de janela. Não pode ser **nulo**.  
  
### <a name="remarks"></a>Comentários 
Se você estiver usando o /permissive-option, DECLARE_WND_CLASS causará um erro de compilação porque ele contém um nome dependente. DECLARE_WND_CLASS2 exige que você nomear explicitamente a classe que essa macro é usada em e não causa o erro sob o /permissive-flag.
Caso contrário, essa macro é idêntica ao [DECLARE_WND_CLASS](#declare_wnd_class).
   
##  <a name="declare_wnd_superclass"></a>DECLARE_WND_SUPERCLASS  
 Permite que você especifique os parâmetros de uma classe. Coloca essa macro na classe de controle de um controle ActiveX ATL.  
  
```
DECLARE_WND_SUPERCLASS( WndClassName, OrigWndClassName )
```  
  
### <a name="parameters"></a>Parâmetros  
 `WndClassName`  
 [in] O nome da janela classe superclasse que será `OrigWndClassName`. Se **nulo**, ATL gerará um nome de classe de janela.  
  
 `OrigWndClassName`  
 [in] O nome de uma classe de janela existente.  
  
### <a name="remarks"></a>Comentários  
 Esta macro permite que você especifique o nome de uma classe de janela que será superclasse uma classe de janela existente. [CWndClassInfo](cwndclassinfo-class.md) gerencia as informações de superclasse.  
  
 `DECLARE_WND_SUPERCLASS`implementa a função estática a seguir:  
  
 [!code-cpp[NVC_ATL_Windowing&#127;](../../atl/codesnippet/cpp/window-class-macros_1.cpp)]  
  
 Por padrão, [CWindowImpl](cwindowimpl-class.md) usa o [DECLARE_WND_CLASS](#declare_wnd_class) macro para criar uma janela com base em uma nova classe de janela. Especificando o `DECLARE_WND_SUPERCLASS` macro em um `CWindowImpl`-derivado da classe, a classe de janela será baseada em uma classe existente, mas usará seu procedimento de janela. Essa técnica é chamada superclassing.  
  
 Além de usar o `DECLARE_WND_CLASS` e `DECLARE_WND_SUPERCLASS` macros, você pode substituir o [GetWndClassInfo](cwindowimpl-class.md#getwndclassinfo) função com sua própria implementação.  

  
 Para obter mais informações sobre como usar o windows em ATL, consulte o artigo [Classes de janela ATL](../../atl/atl-window-classes.md).  
  
##  <a name="declare_wnd_class_ex"></a>DECLARE_WND_CLASS_EX  
 Permite que você especifique o nome de uma classe de janela existente no qual uma nova classe de janela será baseada. Coloca essa macro na classe de controle de um controle ActiveX ATL.  
  
```
DECLARE_WND_CLASS_EX( WndClassName, style, bkgnd )
```  
  
### <a name="parameters"></a>Parâmetros  
 `WndClassName`  
 [in] O nome da nova classe de janela. Se **nulo**, ATL gerará um nome de classe de janela.  
  
 `style`  
 [in] O estilo da janela.  
  
 *plano de fundo*  
 [in] A cor de plano de fundo da janela.  
  
### <a name="remarks"></a>Comentários  
 Esta macro permite que você especifique os parâmetros de classe de uma nova classe de janela, cujas informações serão gerenciadas pelo [CWndClassInfo](cwndclassinfo-class.md). `DECLARE_WND_CLASS_EX`Define a nova classe de janela, Implementando a função estática a seguir:  
  
 [!code-cpp[NVC_ATL_Windowing&#127;](../../atl/codesnippet/cpp/window-class-macros_1.cpp)]  
  
 Se você quiser usar os estilos padrão e a cor de plano de fundo, use o [DECLARE_WND_CLASS](#declare_wnd_class) macro. Para obter mais informações sobre como usar o windows em ATL, consulte o artigo [Classes de janela ATL](../../atl/atl-window-classes.md).  
  
## <a name="see-also"></a>Consulte também  
 [Macros](atl-macros.md)










