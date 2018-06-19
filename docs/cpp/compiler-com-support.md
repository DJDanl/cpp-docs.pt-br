---
title: Suporte COM do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- cl.exe compiler, COM support
- COM, compiler support
ms.assetid: 76a78442-f2a4-4985-9967-67e20773f847
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8d6e916cbd7cd8f5fbb259ff096159f9a49202ac
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32412706"
---
# <a name="compiler-com-support"></a>Suporte para COM do compilador
## <a name="microsoft-specific"></a>Específico da Microsoft  
 O compilador do Visual C++ pode ler bibliotecas de tipos COM (Component Object Model) diretamente e converter o conteúdo em um código-fonte do C++ que pode ser incluído na compilação. Há extensões de linguagem disponíveis para facilitar a programação COM do lado do cliente.  
  
 Usando o [diretiva de pré-processador #import](../preprocessor/hash-import-directive-cpp.md), o compilador pode ler uma biblioteca de tipos e converter em um arquivo de cabeçalho do C++ que descreve o COM interfaces como classes. Um conjunto de atributos de `#import` está disponível para o usuário controlar o conteúdo referente aos arquivos resultantes de cabeçalho de biblioteca de tipos.  
  
 Você pode usar o [declspec](../cpp/declspec.md) atributo estendido [uuid](../cpp/uuid-cpp.md) para atribuir um identificador global exclusivo (GUID) para um objeto COM. A palavra-chave [uuidof](../cpp/uuidof-operator.md) pode ser usado para extrair o GUID associado a um objeto COM. Outro `__declspec` atributo, [propriedade](../cpp/property-cpp.md), pode ser usado para especificar o **obter** e **definir** métodos para um membro de dados de um objeto COM.  
  
 Um conjunto de classes e funções globais do COM suporte é fornecido para dar suporte a **VARIANT** e `BSTR` tipos, implementar ponteiros inteligentes e encapsular o objeto de erro gerado pelo `_com_raise_error`:  
  
-   [Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)  
  
-   [_bstr_t](../cpp/bstr-t-class.md)  
  
-   [_com_error](../cpp/com-error-class.md)  
  
-   [_com_ptr_t](../cpp/com-ptr-t-class.md)  
  
-   [_variant_t](../cpp/variant-t-class.md)  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classes de suporte COM do compilador](../cpp/compiler-com-support-classes.md)   
 [Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)