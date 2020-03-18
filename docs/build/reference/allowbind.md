---
title: /ALLOWBIND
ms.date: 11/04/2016
f1_keywords:
- /allowbind_bind
helpviewer_keywords:
- ALLOWBIND editbin option
- /ALLOWBIND editbin option
- -ALLOWBIND editbin option
ms.assetid: eaadbb8c-4339-4281-9a75-3a1ce2352ff8
ms.openlocfilehash: 4f5b662223914cbb4970188595afb52cc2500cd4
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79440380"
---
# <a name="allowbind"></a>/ALLOWBIND

Especifica se uma DLL pode ser associada.

```

/ALLOWBIND[:NO]
```

## <a name="remarks"></a>Comentários

A opção **/ALLOWBIND** define um bit no cabeçalho de uma DLL que indica ao BIND. exe que a imagem pode ser associada. A associação pode permitir que uma imagem seja carregada mais rapidamente quando o carregador não precisa trocar de base e executar a correção de endereço para cada DLL referenciada. Talvez você não queira que uma DLL seja associada se tiver sido assinada digitalmente – a associação invalida a assinatura. A associação não tem efeito se a ASLR (Address Space layout Randomization) estiver habilitada para a imagem usando **/DynamicBase** em versões do Windows que dão suporte a ASLR.

Use **/ALLOWBIND: no** para impedir que o BIND. exe VINCULE a dll.

Para obter mais informações, consulte a opção vinculador [/ALLOWBIND](allowbind-prevent-dll-binding.md) .

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](editbin-options.md)
