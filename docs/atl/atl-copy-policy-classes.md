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
ms.openlocfilehash: 34b9ed5dca45633a5ab980d38b8a7cda151f5dc7
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="atl-copy-policy-classes"></a>Classes de política de cópia do ATL
Classes de política de cópia são [classes de utilitário](../atl/utility-classes.md) usado para inicializar, copiar e excluir dados. Classes de política de cópia permitem para definir semânticas de cópia para qualquer tipo de dados e define as conversões entre tipos de dados diferentes.  
  
 Classes de política ATL usa cópia em suas implementações dos seguintes modelos:  
  
-   [CComEnumImpl](../atl/reference/ccomenumimpl-class.md)  
  
-   [IEnumOnSTLImpl](../atl/reference/ienumonstlimpl-class.md)  
  
-   [ICollectionOnSTLImpl](../atl/reference/icollectiononstlimpl-class.md)  
  
 Encapsulando as informações necessárias para copiar ou converter dados em uma classe de política de cópia que pode ser passado como um argumento de modelo, os desenvolvedores ATL foi fornecido para a capacidade de reutilização extreme dessas classes. Por exemplo, se você precisa implementar uma coleção usando qualquer tipo de dados arbitrários, você precisa fornecer é a política de cópia apropriado; não é necessário o código que implementa a coleção de toque.  
  
## <a name="definition"></a>Definição  
 Por definição, uma classe que fornece as seguintes funções estáticas é uma classe de política de cópia:  
  
 `static void init(``DestinationType``* p);`  
  
 `static HRESULT copy(` `DestinationType` `* pTo, const`  `SourceType` `* pFrom);`  
  
 `static void destroy(``DestinationType``* p);`  
  
 Você pode substituir os tipos de `DestinationType` e *SourceType* com tipos de dados arbitrário para cada política de cópia.  
  
> [!NOTE]
>  Embora seja possível definir classes de política de cópia de qualquer tipo de dados arbitrários, use as classes de código de ATL deve limitar os tipos que fazem sentido. Por exemplo, quando usando uma política de cópia de classe com implementações de enumerador ou de coleção do ATL `DestinationType` deve ser um tipo que pode ser usado como um parâmetro em um método de interface COM.  
  
 Use **init** para inicializar os dados, **cópia** para copiar dados, e **destruir** para liberar os dados. O significado preciso da inicialização, copiar e destruição de domínio da classe de política de cópia e irão variar dependendo dos tipos de dados envolvidos.  
  
 Há dois requisitos de uso e a implementação de uma classe de política de cópia:  
  
-   O primeiro parâmetro para **cópia** deve receber apenas um ponteiro para dados anteriormente inicializou usando **init**.  
  
-   **destruir** só deve receber um ponteiro para dados anteriormente inicializou usando **init** ou copiados por meio de **cópia**.  
  
## <a name="standard-implementations"></a>Implementações padrão  
 ATL fornece duas classes de política de cópia na forma do **Copy** e **_CopyInterface** classes de modelo:  
  
-   O **Copy** classe permite homogênea copiando somente (não a conversão entre tipos de dados) desde que oferece apenas um parâmetro de modelo único para especificar ambos `DestinationType` e *SourceType*. A implementação deste modelo não contém nenhum código de inicialização ou destruição e usa `memcpy` para copiar os dados. ATL também fornece especializações de **Copy** para **VARIANT**, `LPOLESTR`, **OLEVERB**, e **CONNECTDATA** tipos de dados.  
  
-   O **_CopyInterface** classe fornece uma implementação para copiar os ponteiros de interface seguindo as regras COM padrão. Novamente essa classe permite que apenas copiar homogêneos, portanto, ele usa a atribuição simples e uma chamada para `AddRef` para executar a cópia.  
  
## <a name="custom-implementations"></a>Implementações personalizadas  
 Normalmente, você precisará definir suas próprias classes de política de cópia para copiar heterogêneas (ou seja, a conversão entre tipos de dados). Para obter alguns exemplos de classes de política personalizada de cópia, examine os arquivos VCUE_Copy.h e VCUE_CopyString.h no [ATLCollections](../visual-cpp-samples.md) exemplo. Esses arquivos contêm duas classes de política de cópia de modelo, `GenericCopy` e `MapCopy`, mais um número de especializações de `GenericCopy` para diferentes tipos de dados.  
  
### <a name="genericcopy"></a>GenericCopy  
 `GenericCopy` permite que você especifique o *SourceType* e `DestinationType` como argumentos de modelo. Aqui está a forma mais geral do `GenericCopy` classe de VCUE_Copy.h:  
  
 [!code-cpp[NVC_ATL_COM#30](../atl/codesnippet/cpp/atl-copy-policy-classes_1.h)]  
  
 VCUE_Copy.h também contém as seguintes especializações desta classe: `GenericCopy<BSTR>`, `GenericCopy<VARIANT, BSTR>`, `GenericCopy<BSTR, VARIANT>`. VCUE_CopyString.h contém especializações copiar de **std::string**s: `GenericCopy<std::string>`, `GenericCopy<VARIANT, std::string>`, e `GenericCopy<BSTR, std::string>`. É possível aperfeiçoar `GenericCopy` fornecendo mais especializações de sua preferência.  
  
### <a name="mapcopy"></a>MapCopy  
 `MapCopy` pressupõe-se de que os dados que estão sendo copiados são armazenados em um mapa de estilo de biblioteca C++ padrão, permite que você especifique o tipo de mapa na qual os dados são armazenados e o tipo de destino. A implementação da classe usa apenas as definições de tipo fornecidas pelo *MapType* classe para determinar o tipo da fonte de dados e chamar o `GenericCopy` classe. Nenhum especializações dessa classe são necessários.  
  
 [!code-cpp[NVC_ATL_COM#31](../atl/codesnippet/cpp/atl-copy-policy-classes_2.h)]  
  
## <a name="see-also"></a>Consulte também  
 [Implementação de uma coleção de baseado em biblioteca padrão C++](../atl/implementing-an-stl-based-collection.md)   
 [Exemplo de ATLCollections](../visual-cpp-samples.md)

