---
title: Suporte para COM do compilador
ms.date: 05/06/2019
helpviewer_keywords:
- cl.exe compiler, COM support
- COM, compiler support
ms.assetid: 76a78442-f2a4-4985-9967-67e20773f847
ms.openlocfilehash: 421930088dcbf9762d50b5af37d994b9008890eb
ms.sourcegitcommit: 720b74dddb1cdf4e570d55103158304ee1df81f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/29/2019
ms.locfileid: "68606383"
---
# <a name="compiler-com-support"></a>Suporte para COM do compilador

## <a name="microsoft-specific"></a>Específico da Microsoft

O compilador C++ da Microsoft pode ler diretamente bibliotecas de tipo com (modelo de objeto de componente) e C++ converter o conteúdo em código-fonte que pode ser incluído na compilação. As extensões de linguagem estão disponíveis para facilitar a programação COM no lado do cliente para aplicativos da área de trabalho.

Usando a [diretiva de pré-processador #import](../preprocessor/hash-import-directive-cpp.md), o compilador pode ler uma biblioteca de tipos e convertê-la em C++ um arquivo de cabeçalho que descreve as interfaces com como classes. Um conjunto de atributos de `#import` está disponível para o usuário controlar o conteúdo referente aos arquivos resultantes de cabeçalho de biblioteca de tipos.

Você pode usar o [UUID](../cpp/uuid-cpp.md) do atributo estendido [_ declspec](../cpp/declspec.md) para atribuir um GUID (identificador global exclusivo) a um objeto com. A palavra-chave [__uuidof](../cpp/uuidof-operator.md) pode ser usada para extrair o GUID associado a um objeto com. Outro atributo **_ declspec** , [Property](../cpp/property-cpp.md), pode ser usado para especificar `get` os `set` métodos e para um membro de dados de um objeto com.

Um conjunto de funções e classes globais de suporte de com é fornecido para `VARIANT` dar `BSTR` suporte aos tipos e, implementar ponteiros inteligentes e encapsular o objeto `_com_raise_error`de erro gerado por:

- [Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)

- [_bstr_t](../cpp/bstr-t-class.md)

- [_com_error](../cpp/com-error-class.md)

- [_com_ptr_t](../cpp/com-ptr-t-class.md)

- [_variant_t](../cpp/variant-t-class.md)

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classes de suporte COM do compilador](../cpp/compiler-com-support-classes.md)<br/>
[Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)
