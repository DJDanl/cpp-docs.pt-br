---
title: 'Classe Platform:: array | Microsoft Docs'
ms.custom: 
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- VCCORLIB/Namespace not found::Platform
- VCCORLIB/Namespace not found::Platform::Array Constructors
- VCCORLIB/Namespace not found::Platform::Array::Value
dev_langs:
- C++
helpviewer_keywords:
- Platform::Array Class
ms.assetid: 7815ab40-88c5-42b0-83b8-081cef0cda31
caps.latest.revision: 
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8e3d2964e1488e74e7a07f20c38ee4fbbcf6e387
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="platformarray-class"></a>Classe Platform::Array
Representa uma matriz unidimensional modificável, que pode ser recebida e transmitida pela interface binária de aplicativo (ABI).  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp    
template <typename T>  
private ref class Array<TArg, 1> :   
    public WriteOnlyArray<TArg, 1>,  
    public IBoxArray<TArg>   
```  
  
### <a name="members"></a>Membros  
 Platform::Array herda todos os métodos de [Platform::WriteOnlyArray Class](../cppcx/platform-writeonlyarray-class.md) e implementa a propriedade `Value` da [Platform::IBoxArray Interface](../cppcx/platform-iboxarray-interface.md).  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtores de matriz](#ctor)|Inicializa uma matriz unidimensional e modificável de tipos especificados pelo parâmetro do modelo de classe, *T*.|  
  
### <a name="methods"></a>Métodos  
 Consulte [Platform::WriteOnlyArray Class](../cppcx/platform-writeonlyarray-class.md).  
  
### <a name="properties"></a>Propriedades  
  
|||  
|-|-|  
|[Array::Value](#value)|Recupera um identificador para a matriz atual.|  
  
### <a name="remarks"></a>Comentários  
 A classe da matriz é fechada e não pode ser herdada.  
  
 O sistema de tipos do tempo de execução do Windows não oferece suporte para o conceito de matrizes denteadas e, portanto, você não pode passar um IVector < Platform:: array\<T >> como um parâmetro de método ou valor de retorno. Para passar uma matriz denteada ou uma sequência de sequências através da ABI, use `IVector<IVector<T>^>`.  
  
 Para obter mais informações sobre quando e como usar Platform:: array, consulte [matriz e WriteOnlyArray](../cppcx/array-and-writeonlyarray-c-cx.md).  
  
 O sistema de tipos do tempo de execução do Windows não oferece suporte para o conceito de matrizes denteadas e, portanto, você não pode passar um IVector < Platform:: array\<T >> como um parâmetro de método ou valor de retorno. Para passar uma matriz denteada ou uma sequência de sequências através da ABI, use `IVector<IVector<T>^>`.  
  
 Essa classe é definida no cabeçalho vccorlib.h, que é incluído automaticamente pelo compilador. Ela é visível no Intellisense mas não no Pesquisador de Objetos porque não é um tipo público definido em platform.winmd.  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: **/ZW**  

 
## <a name="ctor"></a>  Construtores de matriz
Inicializa uma matriz unidimensional e modificável de tipos especificados pelo parâmetro do modelo de classe, *T*.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
Array(unsigned int size);  
Array(T* data, unsigned int size);    
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Parâmetro de modelo de classe.  
  
 `size`  
 O número de elementos na matriz.  
  
 `data`  
 Um ponteiro para uma matriz do tipo de dados `T` que é usado para inicializar esse objeto Array.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre como criar instâncias de Platform:: array, consulte [matriz e WriteOnlyArray](../cppcx/array-and-writeonlyarray-c-cx.md).

## <a name="get"></a>  Método Array:
Recupera uma referência ao elemento de matriz no local do índice especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp    
T& get(unsigned int index)  const;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `index`  
 Um índice com base zero que identifica um elemento na matriz. O índice mínimo é 0 e o máximo é o valor especificado pelo `size` parâmetro o [construtor Array](#ctor).  
  
### <a name="return-value"></a>Valor de retorno  
 O elemento de matriz especificado pelo parâmetro `index`.  
  
## <a name="value"></a>  Array::Value Property
Recupera um identificador para a matriz atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp 
property Array^ Value;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para a matriz atual.  

## <a name="see-also"></a>Consulte também  
 [Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)   
 [Matriz e WriteOnlyArray](../cppcx/array-and-writeonlyarray-c-cx.md)