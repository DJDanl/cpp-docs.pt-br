---
title: Reprovando tipos e membros (C++ c++ /CX) | Microsoft Docs
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: language-reference
ms.assetid: b20b01c1-a439-4ff0-8cf3-d7280c492813
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3b2f8ab1c52297a95c89f8ee00053d24baebe39d
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43205474"
---
# <a name="deprecating-types-and-members-ccx"></a>Reprovando tipos e membros (C++/CX)
No C + + c++ /CLI CX, substituição de membros e tipos de tempo de execução do Windows para produtores e consumidores usando o [preterido](/uwp/api/windows.foundation.metadata.deprecatedattribute) atributo tem suporte. Se você consumir uma API para a qual esse atributo foi aplicado, você receberá uma mensagem de aviso de tempo de compilação indicando que a API foi substituída e recomendando também uma API alternativa para uso. Em seus próprios tipos e métodos públicos, você pode aplicar esse atributo e fornecer sua própria mensagem personalizada.  
  
> [!CAUTION]
>  O [preterido](/uwp/api/windows.foundation.metadata.deprecatedattribute) atributo é usado apenas com tipos de tempo de execução do Windows. Para classes C++ padrão e membros, use [__declspec(deprecated)](../cpp/deprecated-cpp.md).  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como substituir suas próprias APIs públicas – por exemplo, em um componente do Tempo de Execução do Windows. O segundo parâmetro do tipo [Windows: Foundation:: Metadata:: deprecationtype](/uwp/api/windows.foundation.metadata.deprecationtype) Especifica se a API está sendo substituída ou removida. Há suporte somente para o valor DeprecationType::Deprecated no momento. O terceiro parâmetro no atributo especifica o [Windows::Foundation::Metadata::Platform](/uwp/api/windows.foundation.metadata.platformattribute) ao qual o atributo se aplica.  
  
```  
  
namespace wfm = Windows::Foundation::Metadata;  
  
public ref class Bicycle sealed  
{  
  
public:  
    property double Speed;  
  
    [wfm::Deprecated("Use the Speed property to compute the angular speed of the wheel", wfm::DeprecationType::Deprecate, 0x0)]  
    double ComputeAngularVelocity();  
};  
```  
  
## <a name="supported-targets"></a>Destinos com suporte  
 A tabela a seguir lista as construções às quais o atributo Deprecated pode ser aplicado:  
  
||  
|-|  
|Controle XAML|  
|delegado|  
|evento|  
|campo enum|  
|enum|  
|struct|  
|method|  
|classe|  
|interface|  
|propriedade|  
|campo struct|  
|construtor parametrizado|  
  
## <a name="see-also"></a>Consulte também  
 [Sistema de tipos](../cppcx/type-system-c-cx.md)   
 [Referência de linguagem do Visual C++](../cppcx/visual-c-language-reference-c-cx.md)   
 [Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)