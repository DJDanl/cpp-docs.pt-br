---
title: Namespace de plataforma (C + + CX) | Microsoft Docs
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: reference
f1_keywords:
- Platform/Platform
dev_langs:
- C++
helpviewer_keywords:
- Platform Namespace (C++/CX)
ms.assetid: b160e822-d424-43d2-ba60-57b0e81f259c
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 348bedcde953cbcd6084023d6f7117c7f7f001f5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="platform-namespace-ccx"></a>Namespace de Plataforma (C++/CX)
Contém os tipos internos que são compatíveis com o Tempo de Execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
using namespace Platform;  
```  
  
### <a name="members"></a>Membros  
 **Atributos**  
  
 O namespace Platform contém atributos, classes, enumerações, interfaces e estruturas. O Platform também contém namespaces aninhados.  
  
|Atributo|Descrição|  
|---------------|-----------------|  
|Sinalizadores|Indica que uma enumeração pode ser tratada como um campo de bits; isto é, um conjunto de sinalizadores.|  
|MTAThread|Indica que o modelo de threading COM para um aplicativo é MTA (Multi-Threaded Apartment).|  
|STAThread|Indica que o modelo de threading para um aplicativo é STA (Single-Threaded Apartment).|  
  
 **Classes**  
  
 O namespace Platform tem as seguintes classes.  
  
|Classe|Descrição|  
|-----------|-----------------|  
|[Classe Platform::AccessDeniedException](../cppcx/platform-accessdeniedexception-class.md)|Gerada quando o acesso a um recurso é negado.|  
|[Classe Platform::Agile](../cppcx/platform-agile-class.md)|Representa um objeto não agile como um objeto agile.|  
|[Classe Platform::Array](../cppcx/platform-array-class.md)|Representa uma matriz modificável unidimensional.|  
|[Classe Platform::ArrayReference](../cppcx/platform-arrayreference-class.md)|Representa uma matriz cuja inicialização é otimizada para minimizar as operações de cópia.|  
|[Classe Platform::Box](../cppcx/platform-box-class.md)|Usado para declarar um tipo demarcado que encapsula um tipo de valor como Windows::Foundation::DateTime ou int64 quando esse tipo é transmitido pela interface binária de aplicativo (ABI) ou armazenado em uma variável do tipo [Platform::Object^](../cppcx/platform-object-class.md).|  
|[Classe Platform::ChangedStateException](../cppcx/platform-changedstateexception-class.md)|Gerada quando os métodos de um iterador de coleção ou uma exibição de coleção são chamados após a alteração da coleção pai, invalidando os resultados do método.|  
|[Classe Platform::ClassNotRegisteredException](../cppcx/platform-classnotregisteredexception-class.md)|Gerada quando uma classe COM não foi registrada.|  
|[Classe Platform::COMException](../cppcx/platform-comexception-class.md)|Representa a exceção que é gerada quando um valor não reconhecido é retornado de uma chamada de método COM.|  
|[Classe Platform::Delegate](../cppcx/platform-delegate-class.md)|Representa a assinatura de um função de retorno de chamada.|  
|[Classe Platform::DisconnectedException](../cppcx/platform-disconnectedexception-class.md)|O objeto foi desconectado de seus clientes.|  
|[Classe Platform::Exception](../cppcx/platform-exception-class.md)|Representa erros que ocorrem durante a execução do aplicativo. A classe base para as exceções.|  
|[Classe Platform::FailureException](../cppcx/platform-failureexception-class.md)|Gerada quando a operação falhou. É o equivalente a E_FAIL HRESULT.|  
|[Classe de valor Platform::Guid](../cppcx/platform-guid-value-class.md)|Representa um GUID no sistema de tipos do Tempo de Execução do Windows.|  
|[Classe Platform::InvalidArgumentException](../cppcx/platform-invalidargumentexception-class.md)|Lançada quando um dos argumentos fornecidos a um método não é válido.|  
|[Classe Platform::InvalidCastException](../cppcx/platform-invalidcastexception-class.md)|Gerada nos casos de conversão inválida ou explícita.|  
|[Classe Platform::MTAThreadAttribute](../cppcx/platform-mtathreadattribute-class.md)|Indica que o modelo de threading COM para um aplicativo é MTA (Multi-Threaded Apartment).|  
|[Classe Platform::NotImplementedException](../cppcx/platform-notimplementedexception-class.md)|Gerada se um método de interface não foi implementado na classe.|  
|[Classe Platform::NullReferenceException](../cppcx/platform-nullreferenceexception-class.md)|Gerada quando ocorre uma tentativa de cancelar a referência de um objeto de referência nula.|  
|[Classe Platform::Object](../cppcx/platform-object-class.md)|Uma classe base que fornece o comportamento comum.|  
|[Classe Platform::ObjectDisposedException](../cppcx/platform-objectdisposedexception-class.md)|Gerada quando uma operação é executada em um objeto descartado.|  
|[Classe Platform::OperationCanceledException](../cppcx/platform-operationcanceledexception-class.md)|Gerada quando uma operação é anulada.|  
|[Classe Platform::OutOfBoundsException](../cppcx/platform-outofboundsexception-class.md)|Gerada quando uma operação tenta acessar dados fora do intervalo válido.|  
|[Classe Platform::OutOfMemoryException](../cppcx/platform-outofmemoryexception-class.md)|Gerada quando a memória para concluir a operação é insuficiente.|  
|[Classe Platform::STAThreadAttribute](../cppcx/platform-stathreadattribute-class.md)|Indica que o modelo de threading para um aplicativo é STA (Single-Threaded Apartment).|  
|[Classe Platform::String](../cppcx/platform-string-class.md)|Uma coleção sequencial de caracteres Unicode que é usada para representar o texto.|  
|[Classe Platform::StringReference](../cppcx/platform-stringreference-class.md)|Permite acesso a buffers de cadeias de caracteres com um mínimo de sobrecarga de cópia.|  
|[Classe Platform::Type](../cppcx/platform-type-class.md)|Identifica um tipo interno por uma enumeração de categoria.|  
|[Classe Platform::ValueType](../cppcx/platform-valuetype-class.md)|A classe base para instâncias de tipos de valor.|  
|[Classe Platform::WeakReference](../cppcx/platform-weakreference-class.md)|Fornece uma referência fraca a objetos da classe ref que não incrementa a contagem de referências.|  
|[Classe Platform::WriteOnlyArray](../cppcx/platform-writeonlyarray-class.md)|Representa uma matriz unidimensional somente gravação que é usada como um parâmetro de entrada em métodos que implementam o padrão FillArray.|  
|[Classe Platform::WrongThreadException](../cppcx/platform-wrongthreadexception-class.md)|Gerada quando um thread chama via um ponteiro de interface, que destina-se a um objeto proxy que não pertence ao apartment do thread.|  
  
 **Implementações de interfaces**  
  
 O namespace Platform define as interfaces a seguir.  
  
|Interface|Descrição|  
|---------------|-----------------|  
|[Interface Platform::IBox](../cppcx/platform-ibox-interface.md)|Usado para transmitir tipos de valor para funções cujos parâmetros são tipados como Platform::Object^.|  
|[Interface Platform::IBoxArray](../cppcx/platform-iboxarray-interface.md)|Interface usada para transmitir matrizes de tipos de valor para funções cujos parâmetros são tipados como Platform::Array.|  
|[Interface Platform::IDisposable](../cppcx/platform-idisposable-interface.md)|Usada para liberar recursos não gerenciados.|  
  
 **Enumerações**  
  
 O namespace Platform tem as enumerações a seguir.  
  
|Interface|Descrição|  
|---------------|-----------------|  
|[Enumeração Platform::CallbackContext](../cppcx/platform-callbackcontext-enumeration.md)|Uma enumeração que é usada como um parâmetro do construtor delegado. Determina se o retorno de chamada deve ter o marshaling para o thread de origem ou o thread chamador.|  
|[Enumeração Platform::TypeCode](../cppcx/platform-typecode-enumeration.md)|Especifica uma categoria numérica que representa um tipo interno.|  
  
 **Estruturas**  
  
 O namespace Platform tem as estruturas a seguir.  
  
|Estrutura|Descrição|  
|---------------|-----------------|  
|[Classe Platform::Enum](../cppcx/platform-enum-class.md)|Representa uma constante nomeada.|  
|[Classe de valor Platform::Guid](../cppcx/platform-guid-value-class.md)|Representa um GUID.|  
|[Classe de valor Platform::IntPtr](../cppcx/platform-intptr-value-class.md)|Um ponteiro com sinal cujo tamanho é apropriado para a plataforma (32 bits ou 64 bits).|  
|[Classe de valor Platform::SizeT](../cppcx/platform-sizet-value-class.md)|Um tipo de dados sem sinal usado para representar o tamanho de um objeto.|  
|[Classe de valor Platform::UIntPtr](../cppcx/platform-uintptr-value-class.md)|Um ponteiro sem sinal cujo tamanho é apropriado para a plataforma (32 bits ou 64 bits).|  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Platform:: Collections](../cppcx/platform-collections-namespace.md)   
 [Namespace Platform::Runtime::CompilerServices](../cppcx/platform-runtime-compilerservices-namespace.md)   
 [Namespace Platform::Runtime::InteropServices](../cppcx/platform-runtime-interopservices-namespace.md)   
 [Namespace Platform::Metadata](../cppcx/platform-metadata-namespace.md)