---
title: 'Classe Platform:: stringreference | Microsoft Docs'
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::StringReference::StringReference
- VCCORLIB/Platform::StringReference::Data
- VCCORLIB/Platform::StringReference::Length
- VCCORLIB/Platform::StringReference::GetHSTRING
- VCCORLIB/Platform::StringReference::GetString
dev_langs:
- C++
ms.assetid: 2d09c7ec-0f16-458e-83ed-7225a1b9221e
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 646a09dd46e123f0bc7eadc178e3741367e908ed
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33097504"
---
# <a name="platformstringreference-class"></a>Classe Platform::StringReference
Um tipo de otimização que você pode usar para transmitir dados de cadeia de caracteres dos parâmetros de entrada `Platform::String^` a outros métodos com um mínimo de operações de cópia.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
class StringReference  
```  
  
### <a name="remarks"></a>Comentários  
  
### <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[StringReference::StringReference](#ctor)|Dois construtores para criar instâncias de `StringReference`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[StringReference::Data](#data)|Retorna os dados da cadeia de caracteres como uma matriz de valores char16.|  
|[StringReference::Length](#length)|Retorna o número de caracteres na cadeia de caracteres.|  
|[StringReference::GetHSTRING](#gethstring)|Retorna os dados da cadeia de caracteres como um HSTRING.|  
|[StringReference::GetString](#getstring)|Retorna os dados da cadeia de caracteres como uma `Platform::String^`.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[StringReference::operator=](#operator-assign)|Atribui uma `StringReference` a uma nova instância de `StringReference` .|  
|[StringReference::operator()](#operator-call)|Converte uma `StringReference` em uma `Platform::String^`.|  
  
### <a name="requirements"></a>Requisitos  
 **Suporte mínimo de cliente:** Windows 8  
  
 **Suporte mínimo de servidor:** Windows Server 2012  
  
 **Namespace:** Platform  
  
 **Cabeçalho:** vccorlib.h  

## <a name="data"></a>  Método Stringreference:
Retorna o conteúdo deste `StringReference` como uma matriz de valores char16.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
const ::default::char16 * Data() const  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma matriz de caracteres de texto UNICODE char16.  
  


## <a name="gethstring"></a>  Método Gethstring
Retorna o conteúdo da cadeia de caracteres como `__abi_HSTRING`.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
__abi_HSTRING GetHSTRING() const  
  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma `__abi_HSTRING` que contém os dados da cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
  


## <a name="getstring"></a>  Método Stringreference:
Retorna o conteúdo da cadeia de caracteres como uma `Platform::String^`.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
__declspec(no_release_return) __declspec(no_refcount)  
    ::Platform::String^ GetString() const  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma `Platform::String^` que contém os dados da cadeia de caracteres.  

## <a name="length"></a>  Método Stringreference:
Retorna o número de caracteres na cadeia de caracteres.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
unsigned int Length() const  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um inteiro sem sinal que especifica o número de caracteres na cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
  


## <a name="operator-assign"></a>  Stringreference:: Operator operador =
Atribui o objeto especificado ao objeto `StringReference` atual.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
StringReference& operator=(const StringReference& __fstrArg);  
StringReference& operator=(const ::default::char16* __strArg);    
```  
  
### <a name="parameters"></a>Parâmetros  
 `__fstrArg`  
 O endereço de um objeto `StringReference` que é usado para inicializar o objeto `StringReference` atual.  
  
 `__strArg`  
 Ponteiro para uma matriz de valores char16 usado para inicializar o objeto `StringReference` atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Referência a um objeto do tipo `StringReference`.  
  
### <a name="remarks"></a>Comentários  
 Porque `StringReference` é uma classe C++ padrão e não uma classe ref, ela não aparece no **Pesquisador de objetos**.  
  


## <a name="operator-call"></a>  Operador de StringReference::operator()
Converte um objeto `StringReference` em um objeto `Platform::String^`.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
  
__declspec(no_release_return) __declspec(no_refcount)  
         operator ::Platform::String^() const  
  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador de um objeto do tipo `Platform::String`.  

## <a name="ctor"></a>  Construtor StringReference::StringReference
Inicializa uma nova instância da classe `StringReference`.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
  
    StringReference();  
  
   StringReference(const StringReference& __fstrArg)  
  
StringReference(const ::default::char16* __strArg)  
  
StringReference(const ::default::char16* __strArg, size_t __lenArg)  
```  
  
### <a name="parameters"></a>Parâmetros  
 `__fstrArg`  
 A `StringReference` cujos dados são usados para inicializar a nova instância.  
  
 `__strArg`  
 Ponteiro para uma matriz de valores char16 usado para inicializar a nova instância.  
  
 `__lenArg`  
 O número de elementos em `__strArg`.  
  
### <a name="remarks"></a>Comentários  
 A primeira versão desse construtor é o construtor padrão. A segunda versão inicializa uma nova classe da instância de `StringReference` do objeto especificado pelo parâmetro `__fstrArg`. As terceira e quarta sobrecargas inicializam uma nova `StringReference` instância de uma matriz de valores char16. char16 representa um caractere de texto UNICODE de 16 bits.  
  


  
## <a name="see-also"></a>Consulte também  
 [Classe Platform::StringReference](../cppcx/platform-stringreference-class.md)