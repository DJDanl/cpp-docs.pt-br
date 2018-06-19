---
title: Reprovando tipos e membros (C + + CX) | Microsoft Docs
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: language-reference
ms.assetid: b20b01c1-a439-4ff0-8cf3-d7280c492813
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5b82f22f996b0f52889bd76227647ab367118898
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33086789"
---
# <a name="deprecating-types-and-members-ccx"></a>Reprovando tipos e membros (C++/CX)
Em C + + CX, substituição de tipos do tempo de execução do Windows e membros para produtores e consumidores usando o [preterido](http://msdn.microsoft.com/en-us/8b02ad36-3b5f-4361-888b-e6a99040e57c) atributo tem suporte. Se você consumir uma API para a qual esse atributo foi aplicado, você receberá uma mensagem de aviso de tempo de compilação indicando que a API foi substituída e recomendando também uma API alternativa para uso. Em seus próprios tipos e métodos públicos, você pode aplicar esse atributo e fornecer sua própria mensagem personalizada.  
  
> [!CAUTION]
>  O [preterido](http://msdn.microsoft.com/en-us/8b02ad36-3b5f-4361-888b-e6a99040e57c) atributo for para uso apenas com tipos de tempo de execução do Windows. Para classes e membros C++ padrão, use [__declspec(deprecated)](http://msdn.microsoft.com/library/044swk7y.aspx).  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como substituir suas próprias APIs públicas – por exemplo, em um componente do Tempo de Execução do Windows. O segundo parâmetro, do tipo [Windows:Foundation::Metadata::DeprecationType](http://msdn.microsoft.com/en-us/ee01e63d-37d0-4273-accc-fca174f88bfa) especifica se a API está sendo substituída ou removida. Há suporte somente para o valor DeprecationType::Deprecated no momento. O terceiro parâmetro no atributo especifica a [Windows::Foundation::Metadata::Platform](http://msdn.microsoft.com/en-us/1eae292d-1ab7-4d97-a58c-b0beffd51ef5) à qual o atributo se aplica.  
  
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