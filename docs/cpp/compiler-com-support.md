---
title: Suporte para COM do compilador
ms.date: 05/06/2019
helpviewer_keywords:
- cl.exe compiler, COM support
- COM, compiler support
ms.assetid: 76a78442-f2a4-4985-9967-67e20773f847
ms.openlocfilehash: 6ab697e5a090158b034a385e60978cff4a73f488
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857574"
---
# <a name="compiler-com-support"></a>Suporte para COM do compilador

**Seção específica da Microsoft**

O compilador C++ da Microsoft pode ler diretamente bibliotecas de tipo com (modelo de objeto de componente) e C++ converter o conteúdo em código-fonte que pode ser incluído na compilação. As extensões de linguagem estão disponíveis para facilitar a programação COM no lado do cliente para aplicativos da área de trabalho.

Usando a [diretiva de pré-processador #import](../preprocessor/hash-import-directive-cpp.md), o compilador pode ler uma biblioteca de tipos e convertê-la em C++ um arquivo de cabeçalho que descreve as interfaces com como classes. Um conjunto de atributos de `#import` está disponível para o usuário controlar o conteúdo referente aos arquivos resultantes de cabeçalho de biblioteca de tipos.

Você pode usar o [UUID](../cpp/uuid-cpp.md) de atributo estendido [__declspec](../cpp/declspec.md) para atribuir um GUID (identificador global exclusivo) a um objeto com. A palavra-chave [__uuidof](../cpp/uuidof-operator.md) pode ser usada para extrair o GUID associado a um objeto com. Outra **__declspec** atributo, [Propriedade](../cpp/property-cpp.md), pode ser usada para especificar os métodos `get` e `set` para um membro de dados de um objeto com.

Um conjunto de funções e classes globais de suporte de COM é fornecido para dar suporte aos tipos `VARIANT` e `BSTR`, implementar ponteiros inteligentes e encapsular o objeto de erro gerado por `_com_raise_error`:

- [Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)

- [_bstr_t](../cpp/bstr-t-class.md)

- [_com_error](../cpp/com-error-class.md)

- [_com_ptr_t](../cpp/com-ptr-t-class.md)

- [_variant_t](../cpp/variant-t-class.md)

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classes de suporte COM do compilador](../cpp/compiler-com-support-classes.md)<br/>
[Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)
