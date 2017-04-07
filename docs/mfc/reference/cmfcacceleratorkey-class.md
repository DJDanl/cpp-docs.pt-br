---
title: Classe CMFCAcceleratorKey | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCAcceleratorKey
- AFXACCELERATORKEY/CMFCAcceleratorKey
- AFXACCELERATORKEY/CMFCAcceleratorKey::CMFCAcceleratorKey
- AFXACCELERATORKEY/CMFCAcceleratorKey::Format
- AFXACCELERATORKEY/CMFCAcceleratorKey::SetAccelerator
dev_langs:
- C++
helpviewer_keywords:
- CMFCAcceleratorKey class
ms.assetid: d140fbf7-23db-45ea-a63e-414a5ec7b3d5
caps.latest.revision: 36
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
ms.openlocfilehash: 7baa210acfabe8f17e2ab747fd98fe463c2907a2
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcacceleratorkey-class"></a>Classe CMFCAcceleratorKey
Uma classe auxiliar que implementa o mapeamento de teclas virtual e a formatação.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCAcceleratorKey : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCAcceleratorKey::CMFCAcceleratorKey](#cmfcacceleratorkey)|Constrói um objeto `CMFCAcceleratorKey`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCAcceleratorKey::Format](#format)|Converte a estrutura de ACELERAÇÃO para sua representação visual.|  
|[CMFCAcceleratorKey::SetAccelerator](#setaccelerator)|Define a tecla de atalho para o `CMFCAcceleratorKey` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Teclas de aceleração também são conhecidas como teclas de atalho. Se você quiser exibir atalhos de teclado que um usuário digita, o [CMFCAcceleratorKeyAssignCtrl classe](../../mfc/reference/cmfcacceleratorkeyassignctrl-class.md) mapas atalhos de teclado, como Alt + Shift + S para um formato de texto personalizado, como "Alt + Shift + S". Cada `CMFCAcceleratorKey` objeto mapeia uma única tecla de atalho para um formato de texto.  
  
 Para obter mais informações sobre como usar as teclas de atalho e tabelas de teclas aceleradoras, consulte [CKeyboardManager classe](../../mfc/reference/ckeyboardmanager-class.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar um `CMFCAcceleratorKey` objeto e como usar o `Format` método.  
  
 [!code-cpp[30 NVC_MFC_RibbonApp](../../mfc/reference/codesnippet/cpp/cmfcacceleratorkey-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CMFCAcceleratorKey`   
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxacceleratorkey.h  
  
##  <a name="cmfcacceleratorkey"></a>CMFCAcceleratorKey::CMFCAcceleratorKey  
 Constrói uma [CMFCAcceleratorKey](../../mfc/reference/cmfcacceleratorkey-class.md) objeto.  
  
```  
CMFCAcceleratorKey();  
CMFCAcceleratorKey(LPACCEL lpAccel);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpAccel`  
 Um ponteiro para uma tecla de atalho.  
  
### <a name="remarks"></a>Comentários  
 Se você não fornecer uma tecla de atalho quando você cria um `CMFCAccleratorKey`, use o [CMFCAcceleratorKey::SetAccelerator](#setaccelerator) método para associar uma tecla de atalho com seu `CMFCAcceleratorKey` objeto.  
  
##  <a name="format"></a>CMFCAcceleratorKey::Format  
 Converte a estrutura de ACELERAÇÃO para o valor de cadeia de caracteres associado.  
  
```  
void Format(CString& str) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `str`  
 Uma referência a um `CString` objeto onde o método grava a tecla de atalho traduzidos.  
  
### <a name="remarks"></a>Comentários  
 Esse método recupera o formato de cadeia de caracteres a tecla de atalho associada. Você pode definir o formato de cadeia de caracteres de um [CMFCAcceleratorKey](../../mfc/reference/cmfcacceleratorkey-class.md) usando o método ou o construtor do objeto [CMFCAcceleratorKey::SetAccelerator](#setaccelerator).  
  
##  <a name="setaccelerator"></a>CMFCAcceleratorKey::SetAccelerator  
 Define a tecla de atalho para o [CMFCAcceleratorKey](../../mfc/reference/cmfcacceleratorkey-class.md) objeto.  
  
```  
void SetAccelerator(LPACCEL lpAccel);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpAccel`  
 Um ponteiro para uma tecla de atalho.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para definir a tecla de atalho para um `CMFCAcceleratorKey` se você não fornece uma tecla de atalho quando você criou o `CMFCAcceleratorKey`.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CKeyboardManager](../../mfc/reference/ckeyboardmanager-class.md)

