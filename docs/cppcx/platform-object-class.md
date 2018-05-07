---
title: 'Classe Platform:: Object | Microsoft Docs'
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Object::Object
- VCCORLIB/Platform::Object::Equals
- VCCORLIB/Platform::Object::GetHashCode
- VCCORLIB/Platform::Object::ReferenceEquals
- VCCORLIB/Platform::ToString
- VCCORLIB/Platform::GetType
dev_langs:
- C++
helpviewer_keywords:
- Object class
ms.assetid: 709e84a8-0bff-471b-bc14-63e424080b5a
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a7fc6dc1df1d1e22032dbe7322b9a6ead8334ddc
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="platformobject-class"></a>Classe Platform::Object
Fornece o comportamento comum para classes e estruturas ref em aplicativos de tempo de execução do Windows. Todas as instâncias de classe e estrutura ref podem ser convertidas implicitamente em Platform::Object^ e podem substituir o método virtual ToString.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
public ref class Object : Object  
```  
  
### <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Object::Object](#ctor)|Inicializa uma nova instância da classe Object.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[: Equals](#equals)|Determina se o objeto especificado é igual ao objeto atual.|  
|[Object::GetHashCode](#gethashcode)|Retorna o código hash para essa instância.|  
|[Object::ReferenceEquals](#referenceequals)|Determina se as instâncias de Object especificadas são a mesma instância.|  
|[ToString](#tostring)|Retorna uma cadeia de caracteres que representa o objeto atual. Pode ser substituído.|  
|[GetType](#gettype)|Obtém um [Platform::Type](../cppcx/platform-type-class.md) que descreve a instância atual.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `Object`  
  
 `Object`  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** vccorlib.h  
  
 **Namespace:** Platform  

  
## <a name="equals"></a> Método: Equals
Determina se o objeto especificado é igual ao objeto atual.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
  
bool Equals(  
    Object^ obj  
)  
```  
  
### <a name="parameters"></a>Parâmetros  
 obj  
 O objeto a ser comparado.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se os objetos forem iguais; caso contrário, `false`.  
  


## <a name="gethashcode"></a>  Método: GetHashCode
Retorna o valor de identidade `IUnknown`* para essa instância se for um objeto COM, ou um valor de hash calculado se não for um objeto COM.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
public:int GetHashCode()  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Valor numérico que identifica esse objeto de forma exclusiva.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar GetHashCode para criar chaves para objetos em mapas. Você pode comparar códigos hash usando [: Equals](#equals). Se o caminho do código for extremamente crítico e `GetHashCode` e `Equals` não forem suficientemente rápidos, você poderá passar para a camada COM subjacente e fazer comparações do ponteiro `IUnknown` nativo.  
  


## <a name="gettype"></a>  Método: GetType
Retorna um [Platform:: Type](../cppcx/platform-type-class.md) objeto que descreve o tipo de tempo de execução de um objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
Object::GetType()  
```  

  
### <a name="property-valuereturn-value"></a>Valor da propriedade/valor de retorno  
 Um [Platform:: Type](../cppcx/platform-type-class.md) objeto que descreve o tipo de tempo de execução do objeto.  
  
### <a name="remarks"></a>Comentários  
 Estático [GetTypeCode](../cppcx/platform-type-class.md#gettypecode) pode ser usado para obter um [enumeração Platform:: TypeCode](../cppcx/platform-typecode-enumeration.md) valor que representa o tipo atual. Isso é mais útil para tipos internos. O código de tipo para qualquer classe ref além [Platform:: string](../cppcx/platform-string-class.md) é Object (1).  
  
 O [Windows::UI::Xaml::Interop::TypeName](http://msdn.microsoft.com/library/windows/apps/windows.ui.xaml.interop.typename.aspx) classe é usada nas APIs do Windows como uma maneira independente de linguagem de transmitir informações de tipo entre os aplicativos e componentes do Windows. O T[classe Platform:: Type](../cppcx/platform-type-class.md) tem operadores para a conversão entre `Type` e `TypeName`.  
  
 Use o [typeid](../windows/typeid-cpp-component-extensions.md) operador para retornar um `Platform::Type` objeto para um nome de classe, por exemplo, ao navegar entre páginas XAML:  
  
```  
rootFrame->Navigate(TypeName(MainPage::typeid), e->Arguments);  
```  
  
## <a name="see-also"></a>Consulte também  
 [Classe Platform:: Type](../cppcx/platform-type-class.md)   
 [Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)   
 [Tipo System] (.. /cppcx/Type-System-c-CX.MD
  
## <a name="ctor"></a>  Construtor Object:: Object
Inicializa uma nova instância da classe Object.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
public:Object()  
```  

## <a name="referenceequals"></a>  Método: ReferenceEquals
Determina se as instâncias de Object especificadas são a mesma instância.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
public:static bool ReferenceEquals(  Object^ obj1,   Object^ obj2)  
```  
  
### <a name="parameters"></a>Parâmetros  
 obj1  
 O primeiro objeto a ser comparado.  
  
 obj2  
 O segundo objeto a ser comparado.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se os dois objetos forem iguais; caso contrário, `false`.  
 
## <a name="tostring"></a>  Método Object:: ToString (C + + CX)
Retorna uma cadeia de caracteres que representa o objeto atual.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
public:  
virtual String^ ToString()  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia de caracteres que representa o objeto atual. Você pode substituir esse método para fornecer uma mensagem de cadeia de caracteres personalizada em sua classe ref ou struct:  
  
```cpp  
public ref class Tree sealed  
{  
public:  
    Tree(){}  
    virtual Platform::String^ ToString() override  
    {  
      return "I’m a Tree";  
    };  
};  
```  
## <a name="see-also"></a>Consulte também  
 [Namespace de plataforma](platform-namespace-c-cx.md)