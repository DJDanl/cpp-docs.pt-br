---
title: Classe CMFCAcceleratorKey | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
- CMFCAcceleratorKey [MFC], CMFCAcceleratorKey
- CMFCAcceleratorKey [MFC], Format
- CMFCAcceleratorKey [MFC], SetAccelerator
ms.assetid: d140fbf7-23db-45ea-a63e-414a5ec7b3d5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7e04bcdf797f7036d943219f9d067dcbf786cfa3
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37039775"
---
# <a name="cmfcacceleratorkey-class"></a>Classe CMFCAcceleratorKey
Uma classe auxiliar que implementa o mapeamento de chave virtual e a formatação.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCAcceleratorKey : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCAcceleratorKey::CMFCAcceleratorKey](#cmfcacceleratorkey)|Constrói um objeto `CMFCAcceleratorKey`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCAcceleratorKey::Format](#format)|Converte a estrutura de ACELERAÇÃO em sua representação visual.|  
|[CMFCAcceleratorKey::SetAccelerator](#setaccelerator)|Define a tecla de atalho para o `CMFCAcceleratorKey` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Teclas de aceleração também são conhecidas como teclas de atalho. Se você deseja exibir atalhos de teclado que um usuário digita, o [CMFCAcceleratorKeyAssignCtrl classe](../../mfc/reference/cmfcacceleratorkeyassignctrl-class.md) mapas atalhos de teclado, como Alt + Shift + S para um formato de texto personalizado, como "Alt + Shift + S". Cada `CMFCAcceleratorKey` objeto mapeia uma tecla de atalho único para um formato de texto.  
  
 Para obter mais informações sobre como usar as teclas de atalho e tabelas de teclas aceleradoras, consulte [CKeyboardManager classe](../../mfc/reference/ckeyboardmanager-class.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um `CMFCAcceleratorKey` objeto e como usar o `Format` método.  
  
 [!code-cpp[NVC_MFC_RibbonApp#30](../../mfc/reference/codesnippet/cpp/cmfcacceleratorkey-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CMFCAcceleratorKey`   
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxacceleratorkey.h  
  
##  <a name="cmfcacceleratorkey"></a>  CMFCAcceleratorKey::CMFCAcceleratorKey  
 Constrói um [CMFCAcceleratorKey](../../mfc/reference/cmfcacceleratorkey-class.md) objeto.  
  
```  
CMFCAcceleratorKey();  
CMFCAcceleratorKey(LPACCEL lpAccel);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *lpAccel*  
 Um ponteiro para uma tecla de atalho.  
  
### <a name="remarks"></a>Comentários  
 Se você não fornecer uma tecla de atalho quando você cria um `CMFCAccleratorKey`, use o [CMFCAcceleratorKey::SetAccelerator](#setaccelerator) método para associar uma tecla de atalho com seu `CMFCAcceleratorKey` objeto.  
  
##  <a name="format"></a>  CMFCAcceleratorKey::Format  
 Converte a estrutura de ACELERAÇÃO para o valor de cadeia de caracteres associada.  
  
```  
void Format(CString& str) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] *str*  
 Uma referência a um `CString` objeto onde o método grava a tecla de atalho traduzidos.  
  
### <a name="remarks"></a>Comentários  
 Esse método retorna o formato de cadeia de caracteres a tecla de atalho associada. Você pode definir o formato de cadeia de caracteres de um [CMFCAcceleratorKey](../../mfc/reference/cmfcacceleratorkey-class.md) usando o método ou o construtor do objeto [CMFCAcceleratorKey::SetAccelerator](#setaccelerator).  
  
##  <a name="setaccelerator"></a>  CMFCAcceleratorKey::SetAccelerator  
 Define a tecla de atalho para o [CMFCAcceleratorKey](../../mfc/reference/cmfcacceleratorkey-class.md) objeto.  
  
```  
void SetAccelerator(LPACCEL lpAccel);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *lpAccel*  
 Um ponteiro para uma tecla de atalho.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para definir a tecla de atalho para um `CMFCAcceleratorKey` se você não fornece uma tecla de atalho quando você criou o `CMFCAcceleratorKey`.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CKeyboardManager](../../mfc/reference/ckeyboardmanager-class.md)
