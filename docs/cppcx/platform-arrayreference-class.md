---
title: 'Classe Platform:: arrayreference | Microsoft Docs'
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::ArrayReference::ArrayReference
dev_langs:
- C++
helpviewer_keywords:
- Platform::ArrayReference Class
ms.assetid: 9ab3b15e-8a60-4600-8fcb-7d6c86284f4b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a7b2a0fd8c4903852e88fa80f12bc05894625888
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42588305"
---
# <a name="platformarrayreference-class"></a>Classe Platform::ArrayReference
`ArrayReference` é um tipo de otimização que você pode substituir por [Platform::Array^](../cppcx/platform-array-class.md) em parâmetros de entrada quando você deseja preencher uma matriz de estilo C com os dados de entrada.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
class ArrayReference  
```
  
### <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Arrayreference:: Arrayreference](#ctor)|Inicializa uma nova instância da classe `ArrayReference`.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador ArrayReference::operator()](#operator-call)|Converte essa `ArrayReference` em uma `Platform::Array<T>^*`.|  
|[Operador ArrayReference::operator=](#operator-assign)|Atribui o conteúdo de outra `ArrayReference` a essa instância.|  
  
## <a name="exceptions"></a>Exceções  
  
### <a name="remarks"></a>Comentários  
 Usando `ArrayReference` para preencher uma matriz de estilo C, você evita a operação de cópia adicional que estaria envolvida ao copiar primeiramente em uma variável `Platform::Array` e, em seguida, na matriz de estilo C. Quando você usa `ArrayReference`, há apenas uma operação de cópia. Para obter um exemplo de código, consulte [matriz e WriteOnlyArray](../cppcx/array-and-writeonlyarray-c-cx.md).  
  
### <a name="requirements"></a>Requisitos  
 **Mínimo de cliente com suporte:** Windows 8  
  
 **Mínimo de servidor com suporte:** Windows Server 2012  
  
 **Namespace:** Platform  
  
 **Cabeçalho:** vccorlib.h  
  
## <a name="ctor"></a>  Construtor arrayreference:: Arrayreference
Inicializa uma nova instância dos [arrayreference](../cppcx/platform-arrayreference-class.md) classe.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
ArrayReference(TArg* ataArg, unsigned int sizeArg, bool needsInitArg = false);  
ArrayReference(ArrayReference&& otherArg)  
  
```  
  
### <a name="parameters"></a>Parâmetros  
 `dataArg`  
 Ponteiro para os dados de matriz.  
  
 `sizeArg`  
 O número de elementos na matriz de origem.  
  
 `otherArg`  
 Objeto `ArrayReference` cujos dados serão movidos para inicializar a nova instância.  
  
### <a name="remarks"></a>Comentários  
  


## <a name="operator-assign"></a>  Arrayreference:: Operator operador =
Atribui o objeto especificado ao atual [arrayreference](../cppcx/platform-arrayreference-class.md) objeto usando a semântica de movimentação.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
  
ArrayReference& operator=(ArrayReference&& otherArg);  
  
```  
  
### <a name="parameters"></a>Parâmetros  
 `otherArg`  
 O objeto que é movido para o objeto `ArrayReference` atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Referência a um objeto do tipo `ArrayReference`.  
  
### <a name="remarks"></a>Comentários  
 `Platform::ArrayReference` é um modelo de classe C++ padrão, não uma classe de referência.  
  


## <a name="operator-call"></a>  Operador Arrayreference
Converte o atual [Platform:: arrayreference](../cppcx/platform-arrayreference-class.md) do objeto para um [Platform:: array](../cppcx/platform-array-class.md) classe.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
  
Array<TArg>^ operator ();  
  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para um objeto do tipo `Array<TArg>^`  
  
### <a name="remarks"></a>Comentários  
 [Platform:: arrayreference](../cppcx/platform-arrayreference-class.md) e [Platform:: array](../cppcx/platform-array-class.md) são classes de modelos de classe C++ padrão, não ref.  
  


  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Platform](../cppcx/platform-namespace-c-cx.md)