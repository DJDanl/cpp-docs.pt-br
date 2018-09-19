---
title: Classes de suporte COM do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_raise_error
dev_langs:
- C++
helpviewer_keywords:
- cl.exe compiler, COM support
- COM, compiler support
ms.assetid: 6d800d9b-b902-4033-9639-740a30b06f88
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a3403a09700ba6f84792cc570d9fb093026241d8
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46070815"
---
# <a name="compiler-com-support-classes"></a>Classes de suporte COM do compilador

**Seção específica da Microsoft**

As classes padrão são usadas para dar suporte a alguns dos tipos COM. As classes são definidas no \<comdef > e os arquivos de cabeçalho gerados a partir da biblioteca de tipos.

|Classe|Finalidade|
|-----------|-------------|
|[_bstr_t](../cpp/bstr-t-class.md)|Encapsula o tipo `BSTR` para fornecer operadores e métodos úteis.|
|[_com_error](../cpp/com-error-class.md)|Define o objeto de erro gerado pelo [com_raise_error](../cpp/com-raise-error.md) na maioria das falhas.|
|[_com_ptr_t](../cpp/com-ptr-t-class.md)|Encapsula ponteiros de interface COM e automatiza as chamadas necessárias para `AddRef`, `Release`, e `QueryInterface`.|
|[_variant_t](../cpp/variant-t-class.md)|Encapsula o tipo `VARIANT` para fornecer operadores e métodos úteis.|

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Suporte para COM do compilador](../cpp/compiler-com-support.md)<br/>
[Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)<br/>
[Referência da linguagem C++](../cpp/cpp-language-reference.md)