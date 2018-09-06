---
title: Classes de política de cópia ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- data [C++], ATL
- classes [C++], copy policy
- copy policy classes [C++]
- _Copy class
- _CopyInterface class
ms.assetid: 06704b68-d318-4c5d-a65b-71457fe9d00d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: aac3952ff05e7b147418d4282b31e8a35572c9b0
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43756527"
---
# <a name="atl-copy-policy-classes"></a>Classes de política de cópia da ATL

Classes de política de cópia são [classes de utilitário](../atl/utility-classes.md) usado para inicializar, copiar e excluir dados. Classes de política de cópia permitem que você definir a semântica de cópia para qualquer tipo de dados e define as conversões entre tipos de dados diferentes.

Classes de política ATL usa cópia em suas implementações dos modelos a seguir:

- [CComEnumImpl](../atl/reference/ccomenumimpl-class.md)

- [IEnumOnSTLImpl](../atl/reference/ienumonstlimpl-class.md)

- [ICollectionOnSTLImpl](../atl/reference/icollectiononstlimpl-class.md)

Encapsulando as informações necessárias para copiar nem converter os dados em uma classe de política de cópia que pode ser passado como um argumento de modelo, os desenvolvedores ATL tem fornecido para reutilização extreme dessas classes. Por exemplo, se você precisar implementar uma coleção usando qualquer tipo de dados arbitrários, tudo o que você precisa fornecer é a política de cópia apropriada; Você nunca precise tocar no código que implementa a coleção.

## <a name="definition"></a>Definição

Por definição, uma classe que fornece as seguintes funções estáticas é uma classe de política de cópia:

`static void init(``DestinationType``* p);`

`static HRESULT copy(` `DestinationType` `* pTo, const`  `SourceType` `* pFrom);`

`static void destroy(``DestinationType``* p);`

Você pode substituir os tipos `DestinationType` e *SourceType* com tipos de dados arbitrários para cada política de cópia.

> [!NOTE]
>  Embora seja possível definir classes de política de cópia para qualquer tipo de dados arbitrários, use as classes de código ATL deve limitar os tipos que fazem sentido. Por exemplo, quando usando uma política de cópia a classe com implementações de enumerador, ou a coleção da ATL `DestinationType` deve ser um tipo que pode ser usado como um parâmetro em um método de interface COM.

Use **init** inicializar dados, **cópia** para copiar dados, e **destruir** para liberar os dados. O significado preciso da inicialização, copiando e destruição são o domínio da classe de política de cópia e irá variar dependendo dos tipos de dados envolvidos.

Há dois requisitos sobre o uso e a implementação de uma classe de política de cópia:

- O primeiro parâmetro para **cópia** só deve receber um ponteiro para dados que você inicializou anteriormente usando **init**.

- **destruir** só deve receber um ponteiro para dados que você inicializou anteriormente usando **init** ou copiados por meio **cópia**.

## <a name="standard-implementations"></a>Implementações padrão

ATL fornece duas classes de política de cópia na forma do `_Copy` e `_CopyInterface` classes de modelo:

- O `_Copy` classe permite homogêneo copiando somente (não a conversão entre tipos de dados), pois ele oferece apenas um único parâmetro de modelo para especificar ambos `DestinationType` e *SourceType*. A implementação genérica desse modelo não contém nenhum código de inicialização ou destruição e usa `memcpy` para copiar os dados. ATL também oferece especializações `_Copy` para tipos de dados VARIANTE, LPOLESTR, OLEVERB e CONNECTDATA.

- O `_CopyInterface` classe fornece uma implementação para a cópia de ponteiros de interface seguindo as regras padrão de COM. Mais uma vez essa classe permite que apenas copiar homogêneos, portanto, ele usa uma atribuição simples e uma chamada para `AddRef` para realizar a cópia.

## <a name="custom-implementations"></a>Implementações personalizadas

Normalmente, você precisará definir suas próprias classes de política de cópia para copiar heterogêneas (ou seja, a conversão entre tipos de dados). Para obter alguns exemplos de classes de política de cópia personalizada, examine os arquivos VCUE_Copy.h e VCUE_CopyString.h na [ATLCollections](../visual-cpp-samples.md) exemplo. Esses arquivos contêm duas classes de política de cópia de modelo, `GenericCopy` e `MapCopy`, além de várias especializações de `GenericCopy` para diferentes tipos de dados.

### <a name="genericcopy"></a>GenericCopy

`GenericCopy` permite que você especifique o *SourceType* e `DestinationType` como argumentos de modelo. Aqui está a forma mais geral do `GenericCopy` classe da VCUE_Copy.h:

[!code-cpp[NVC_ATL_COM#30](../atl/codesnippet/cpp/atl-copy-policy-classes_1.h)]

VCUE_Copy.h também contém as seguintes especializações dessa classe: `GenericCopy<BSTR>`, `GenericCopy<VARIANT, BSTR>`, `GenericCopy<BSTR, VARIANT>`. VCUE_CopyString.h contém especializações para a cópia de **std:: string**s: `GenericCopy<std::string>`, `GenericCopy<VARIANT, std::string>`, e `GenericCopy<BSTR, std::string>`. É possível aperfeiçoar `GenericCopy` , fornecendo ainda mais especializações de sua preferência.

### <a name="mapcopy"></a>MapCopy

`MapCopy` pressupõe-se de que os dados que estão sendo copiados são armazenados em um mapa de estilo de biblioteca padrão C++, portanto, ele permite que você especifique o tipo de mapa em que os dados são armazenados e o tipo de destino. A implementação da classe usa apenas as definições de tipo fornecidas pelo *MapType* classe para determinar o tipo da fonte de dados e para chamar o `GenericCopy` classe. Não há especializações dessa classe são necessários.

[!code-cpp[NVC_ATL_COM#31](../atl/codesnippet/cpp/atl-copy-policy-classes_2.h)]

## <a name="see-also"></a>Consulte também

[Implementando uma coleção de baseada na biblioteca padrão C++](../atl/implementing-an-stl-based-collection.md)   
[Exemplo de ATLCollections](../visual-cpp-samples.md)

