---
title: Classes de suporte COM do compilador
ms.date: 11/04/2016
helpviewer_keywords:
- cl.exe compiler, COM support
- COM, compiler support
ms.assetid: 6d800d9b-b902-4033-9639-740a30b06f88
ms.openlocfilehash: 1a9ff7c57965c9ba00881d5fe48501a6138b31d1
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79444427"
---
# <a name="compiler-com-support-classes"></a>Classes de suporte COM do compilador

**Seção específica da Microsoft**

As classes padrão são usadas para dar suporte a alguns dos tipos COM. As classes são definidas em \<comdef. h > e os arquivos de cabeçalho gerados na biblioteca de tipos.

|Classe|Finalidade|
|-----------|-------------|
|[_bstr_t](../cpp/bstr-t-class.md)|Encapsula o tipo `BSTR` para fornecer operadores e métodos úteis.|
|[_com_error](../cpp/com-error-class.md)|Define o objeto de erro gerado por [_com_raise_error](../cpp/com-raise-error.md) na maioria das falhas.|
|[_com_ptr_t](../cpp/com-ptr-t-class.md)|Encapsula ponteiros de interface COM e automatiza as chamadas necessárias para `AddRef`, `Release`e `QueryInterface`.|
|[_variant_t](../cpp/variant-t-class.md)|Encapsula o tipo `VARIANT` para fornecer operadores e métodos úteis.|

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Suporte para COM do compilador](../cpp/compiler-com-support.md)<br/>
[Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)<br/>
[Referência da linguagem C++](../cpp/cpp-language-reference.md)