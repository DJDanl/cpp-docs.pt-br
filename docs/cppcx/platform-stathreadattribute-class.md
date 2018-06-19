---
title: 'Classe Platform:: STAThreadAttribute | Microsoft Docs'
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: reference
f1_keywords:
- COLLECTION/Platform::Platform
- COLLECTION/Platform::Platform::STAThreadAttribute constructor 1
- COLLECTION/Platform::Platform::STAThreadAttribute::Equals
- COLLECTION/Platform::Platform::STAThreadAttribute::GetHashCode
- COLLECTION/Platform::Platform::STAThreadAttribute::ToString
dev_langs:
- C++
helpviewer_keywords:
- Platform::STAThreadAttribute Class
ms.assetid: f97960fc-e673-4d9e-910a-54c8415411c4
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ab58409bf86af77c9b1f751b9978b5e7103bd043
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33089347"
---
# <a name="platformstathreadattribute-class"></a>Classe Platform::STAThreadAttribute
Indica que o modelo de threading para um aplicativo é STA (Single-Threaded Apartment).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
public ref class STAThreadAttribute sealed : Attribute  
```  
  
### <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor STAThreadAttribute 1](#ctor)|Inicializa uma nova instância da classe.|  
  
### <a name="public-methods"></a>Métodos públicos  
 O atributo STAThreadAttribute herda de [classe Platform:: Object](../cppcx/platform-object-class.md). STAThreadAttribute também sobrecarrega ou possui os seguintes membros:  
  
|Nome|Descrição|  
|----------|-----------------|  
|[STAThreadAttribute::Equals](#equals)|Determina se o objeto especificado é igual ao objeto atual.|  
|[STAThreadAttribute::GetHashCode](#gethashcode)|Retorna o código hash para essa instância.|  
|[STAThreadAttribute::ToString](#tostring)|Retorna uma cadeia de caracteres que representa o objeto atual.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `Platform`  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** collection.h  
  
 **Namespace:** Platform  



## <a name="ctor"></a> STAThreadAttribute constructor
Inicializa uma nova instância da classe STAThreadAttribute.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
public:STAThreadAttribute()  
```  
  


## <a name="equals"></a> STAThreadAttribute::Equals
Determina se o objeto especificado é igual ao objeto atual.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
public:virtual override bool Equals(  Object^ obj)  
```  
  
### <a name="parameters"></a>Parâmetros  
 obj  
 O objeto a ser comparado.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se os objetos forem iguais; caso contrário, `false`.  
  


## <a name="gethashcode"></a> STAThreadAttribute::GetHashCode
Retorna o código hash para essa instância.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
public:int GetHashCode()  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O código hash para essa instância.  
  


## <a name="tostring"></a> STAThreadAttribute::ToString
Retorna uma cadeia de caracteres que representa o objeto atual.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
public:String^ ToString()  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia de caracteres que representa o objeto atual.  
  

  
## <a name="see-also"></a>Consulte também  
 [Namespace de plataforma](platform-namespace-c-cx.md)