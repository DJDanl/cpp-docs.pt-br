---
title: Classes de política de cópia atl
ms.date: 11/04/2016
helpviewer_keywords:
- data [C++], ATL
- classes [C++], copy policy
- copy policy classes [C++]
- _Copy class
- _CopyInterface class
ms.assetid: 06704b68-d318-4c5d-a65b-71457fe9d00d
ms.openlocfilehash: f40f31124d4547076249a7459ac4b63cc25305d1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317391"
---
# <a name="atl-copy-policy-classes"></a>Classes de política de cópia atl

As classes de diretiva de cópia são [classes de utilidade](../atl/utility-classes.md) usadas para inicializar, copiar e excluir dados. As classes de diretiva de cópia permitem definir a semântica de cópia para qualquer tipo de dados e definir conversões entre diferentes tipos de dados.

A ATL usa classes de diretiva de cópia em suas implementações dos seguintes modelos:

- [Ccomenumimpl](../atl/reference/ccomenumimpl-class.md)

- [Ienumonstlimpl](../atl/reference/ienumonstlimpl-class.md)

- [Icollectiononstlimpl](../atl/reference/icollectiononstlimpl-class.md)

Encapsulando as informações necessárias para copiar ou converter dados em uma classe de diretiva de cópia que pode ser passada como um argumento de modelo, os desenvolvedores ATL forneceram uma reutilização extrema dessas classes. Por exemplo, se você precisar implementar uma coleta usando qualquer tipo de dados arbitrários, tudo o que você precisa fornecer é a política de cópia apropriada; você nunca tem que tocar no código que implementa a coleção.

## <a name="definition"></a>Definição

Por definição, uma classe que fornece as seguintes funções estáticas é uma classe de diretiva de cópia:

`static void init(` `DestinationType` `* p);`

`static HRESULT copy(` `DestinationType` `* pTo, const`  `SourceType` `* pFrom);`

`static void destroy(` `DestinationType` `* p);`

Você pode substituir `DestinationType` os tipos e o *SourceType* por tipos de dados arbitrários para cada diretiva de cópia.

> [!NOTE]
> Embora você possa definir classes de diretiva de cópia para quaisquer tipos de dados arbitrários, o uso das classes no código ATL deve limitar os tipos que fazem sentido. Por exemplo, ao usar uma classe de diretiva de cópia com `DestinationType` implementações de coleção ou enumeradores da ATL, deve ser um tipo que pode ser usado como parâmetro em um método de interface COM.

Use **init** para inicializar dados, **copiar** para copiar dados e **destruir** para liberar os dados. O significado preciso de inicialização, cópia e destruição são o domínio da classe de diretiva de cópia e variará dependendo dos tipos de dados envolvidos.

Existem dois requisitos sobre o uso e implementação de uma classe de diretiva de cópia:

- O primeiro parâmetro a **copiar** deve receber apenas um ponteiro para os dados que você já inicializou usando **init**.

- **destruir** só deve receber um ponteiro para os dados que você já inicializou usando **init** ou copiado via **cópia**.

## <a name="standard-implementations"></a>Implementações padrão

A ATL fornece duas classes de `_Copy` `_CopyInterface` diretiva de cópia na forma das classes e modelo:

- A `_Copy` classe permite apenas a cópia homogênea (não a conversão entre os tipos `DestinationType` de dados), uma vez que oferece apenas um parâmetro de modelo único para especificar ambos e *SourceType*. A implementação genérica deste modelo não contém `memcpy` nenhum código de inicialização ou destruição e usa para copiar os dados. A ATL também fornece `_Copy` especializações para tipos de dados VARIANT, LPOLESTR, OLEVERB e CONNECTDATA.

- A `_CopyInterface` classe fornece uma implementação para copiar ponteiros de interface seguindo as regras padrão do COM. Mais uma vez, esta classe permite apenas cópias homogêneas, `AddRef` por isso usa uma tarefa simples e uma chamada para executar a cópia.

## <a name="custom-implementations"></a>Implementações personalizadas

Normalmente, você precisará definir suas próprias classes de política de cópia para cópia heterogênea (ou seja, conversão entre tipos de dados). Para alguns exemplos de classes de diretiva de cópia personalizadas, veja os arquivos VCUE_Copy.h e VCUE_CopyString.h na amostra [ATLCollections.](../overview/visual-cpp-samples.md) Esses arquivos contêm duas `GenericCopy` classes `MapCopy`de diretiva de cópia `GenericCopy` de modelos e, além de uma série de especializações de diferentes tipos de dados.

### <a name="genericcopy"></a>Genericcopy

`GenericCopy`permite especificar o *SourceType* e `DestinationType` como argumentos de modelo. Aqui está a forma mais `GenericCopy` geral da classe de VCUE_Copy.h:

[!code-cpp[NVC_ATL_COM#30](../atl/codesnippet/cpp/atl-copy-policy-classes_1.h)]

VCUE_Copy.h também contém as seguintes especializações desta classe: `GenericCopy<BSTR>`, `GenericCopy<VARIANT, BSTR>`, `GenericCopy<BSTR, VARIANT>`. VCUE_CopyString.h contém especializações para cópia de **std::string**s: `GenericCopy<std::string>`, `GenericCopy<VARIANT, std::string>`e `GenericCopy<BSTR, std::string>`. Você poderia `GenericCopy` melhorar fornecendo mais especializações por conta própria.

### <a name="mapcopy"></a>MapCopy

`MapCopy`assume que os dados copiados são armazenados em um mapa c++ estilo Biblioteca Padrão, de modo que permite especificar o tipo de mapa no qual os dados são armazenados e o tipo de destino. A implementação da classe apenas usa os typedefs fornecidos pela classe *MapType* para `GenericCopy` determinar o tipo de dados de origem e para chamar a classe apropriada. Não são necessárias especializações dessa classe.

[!code-cpp[NVC_ATL_COM#31](../atl/codesnippet/cpp/atl-copy-policy-classes_2.h)]

## <a name="see-also"></a>Confira também

[Implementando uma coleção baseada em biblioteca padrão C++](../atl/implementing-an-stl-based-collection.md)<br/>
[Amostra atlcollections](../overview/visual-cpp-samples.md)
