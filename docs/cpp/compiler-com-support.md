---
title: Suporte para COM do compilador
ms.date: 05/06/2019
helpviewer_keywords:
- cl.exe compiler, COM support
- COM, compiler support
ms.assetid: 76a78442-f2a4-4985-9967-67e20773f847
ms.openlocfilehash: 9a5961049cbc54c94cec5b444e2d98f013dda932
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233776"
---
# <a name="compiler-com-support"></a>Suporte para COM do compilador

**Específico da Microsoft**

O compilador do Microsoft C++ pode ler diretamente bibliotecas de tipo COM (modelo de objeto de componente) e converter o conteúdo em código-fonte C++ que pode ser incluído na compilação. As extensões de linguagem estão disponíveis para facilitar a programação COM no lado do cliente para aplicativos da área de trabalho.

Usando a [diretiva de pré-processador #import](../preprocessor/hash-import-directive-cpp.md), o compilador pode ler uma biblioteca de tipos e convertê-la em um arquivo de cabeçalho C++ que descreve as interfaces com como classes. Um conjunto de atributos de `#import` está disponível para o usuário controlar o conteúdo referente aos arquivos resultantes de cabeçalho de biblioteca de tipos.

Você pode usar o [UUID](../cpp/uuid-cpp.md) de atributo estendido [__declspec](../cpp/declspec.md) para atribuir um GUID (identificador global exclusivo) a um objeto com. A palavra-chave [__uuidof](../cpp/uuidof-operator.md) pode ser usada para extrair o GUID associado a um objeto com. Outro **`__declspec`** atributo, [Propriedade](../cpp/property-cpp.md), pode ser usado para especificar os `get` `set` métodos e para um membro de dados de um objeto com.

Um conjunto de funções e classes globais de suporte de COM é fornecido para dar suporte aos `VARIANT` `BSTR` tipos e, implementar ponteiros inteligentes e encapsular o objeto de erro gerado por `_com_raise_error` :

- [Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)

- [_bstr_t](../cpp/bstr-t-class.md)

- [_com_error](../cpp/com-error-class.md)

- [_com_ptr_t](../cpp/com-ptr-t-class.md)

- [_variant_t](../cpp/variant-t-class.md)

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Classes de suporte de COM do compilador](../cpp/compiler-com-support-classes.md)<br/>
[Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)
