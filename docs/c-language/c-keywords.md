---
title: Palavras-chave C | Microsoft Docs
ms.custom: ''
ms.date: 10/09/2018
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- keywords [C]
- redefining keywords
- Microsoft-specific keywords
ms.assetid: 2d932335-97bf-45cd-b367-4ae00db0ff42
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d9a5255609c3abb4846ce08a2163407eee6f240c
ms.sourcegitcommit: 8480f16893f09911f08a58caf684405404f7ac8e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/12/2018
ms.locfileid: "49161899"
---
# <a name="c-keywords"></a>Palavras-chave C

“Palavras-chave” são palavras que têm um significado especial para o compilador C. Nas fases 7 e 8 da conversão, um identificador não pode ter a mesma ortografia e caixa (maiúscula/minúscula) que a palavra-chave C. (Consulte uma descrição de [fases de translação](../preprocessor/phases-of-translation.md) na *Referência de pré-processador*; para obter informações sobre os identificadores, consulte [Identificadores](../c-language/c-identifiers.md).) A linguagem C usa as seguintes palavras-chave:

|||||
|-|-|-|-|
|**auto**|**double**|**int**|**struct**|
|**break**|**else**|**long**|**switch**|
|**case**|**enum**|**register**|**typedef**|
|**char**|**extern**|**return**|**union**|
|**const**|**float**|**short**|**unsigned**|
|**continue**|**for**|**signed**|**void**|
|**default**|**goto**|**sizeof**|**volatile**|
|**do**|**if**|**static**|**while**|

Você não pode redefinir palavras-chave. No entanto, você pode especificar o texto a ser substituído por palavras-chave antes da compilação usando [diretivas de pré-processador](../preprocessor/preprocessor-directives.md) C.

**Seção específica da Microsoft**

O padrão ANSI C permite que os identificadores com dois sublinhados iniciais sejam reservados para implementações de compilador. Portanto, a convenção da Microsoft é preceder nomes de palavras-chave específicas da Microsoft com sublinhados duplos. Essas palavras não podem ser usadas como nomes de identificadores. Para obter uma descrição das regras ANSI para nomear identificadores, inclusive o uso de sublinhados duplos, consulte [Identificadores](../c-language/c-identifiers.md).

As palavras-chave e os identificadores especiais a seguir são reconhecidos pelo compilador Microsoft C:

|||||
|-|-|-|-|
|**__asm**<sup>3</sup>|**dllimport**<sup>2</sup>|**__int8**<sup>3</sup>|**naked**<sup>2</sup>|
|**__based**<sup>1, 3</sup>|**__except**<sup>3</sup>|**__int16**<sup>3</sup>|**__stdcall**<sup>3</sup>|
|**__cdecl**<sup>3</sup>|**__fastcall**|**__int32**<sup>3</sup>|**thread**<sup>2</sup>|
|**__declspec**<sup>3</sup>|**__finally**<sup>3</sup>|**__int64**<sup>3</sup>|**__try**<sup>3</sup>|
|**dllexport**<sup>2</sup>|**__inline**<sup>3</sup>|**__leave**<sup>3</sup>||

<sup>1</sup> A palavra-chave **__based** tem usos limitados para compilações de destino de 32 e 64 bits.

<sup>2</sup> Esses são identificadores especiais quando usados com **__declspec**. Seu uso em outros contextos não é restrito.

<sup>3</sup> Para compatibilidade com versões anteriores, essas palavras-chave estão disponíveis com dois sublinhados à esquerda e um único sublinhado à esquerda quando as extensões da Microsoft estão habilitadas.

As extensões da Microsoft são ativadas por padrão. Para garantir que seus programas sejam totalmente portáteis, você poderá desabilitar as extensões da Microsoft especificando a opção [/Za \(Desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) durante a compilação. Ao fazer isso, algumas palavras-chave específicas da Microsoft são desabilitadas.

Quando as extensões do Microsoft são habilitadas, você pode usar as palavras-chave listadas acima em seus programas. Para estar em conformidade com o ANSI, a maioria dessas palavras-chave são precedidas por um sublinhado duplo. As quatro exceções, **dllexport**, **dllimport**, **naked** e **thread**, são usadas apenas com **__declspec** e, portanto, não exigem um sublinhado duplo à esquerda. Para compatibilidade com versões anteriores, há suporte para as versões de sublinhado único do restante das palavras-chave.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Elementos de C](../c-language/elements-of-c.md)
