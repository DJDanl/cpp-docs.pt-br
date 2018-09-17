---
title: -ALLOWBIND | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /allowbind
dev_langs:
- C++
helpviewer_keywords:
- ALLOWBIND editbin option
- /ALLOWBIND editbin option
- -ALLOWBIND editbin option
ms.assetid: eaadbb8c-4339-4281-9a75-3a1ce2352ff8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0ce0a33ebb0b8b9ba34ac241c8335e9524dec08b
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45715566"
---
# <a name="allowbind"></a>/ALLOWBIND

Especifica se uma DLL pode ser associada.

```

/ALLOWBIND[:NO]
```

## <a name="remarks"></a>Comentários

O **/ALLOWBIND** opção define um bit no cabeçalho de uma DLL que indica a Bind.exe que a imagem tem permissão para ser associado. Associação pode permitir que uma imagem a ser carregado mais rapidamente quando o carregador não precisa trocar base e realizar o ajuste de endereço para cada DLL referenciada. Talvez você não queira uma DLL seja vinculada caso ela tenha sido assinada digitalmente — associação invalida a assinatura. Associação não tem nenhum efeito se randomização de layout de espaço de endereço (ASLR) estiver habilitada para a imagem por meio **/DYNAMICBASE** em versões do Windows que dão suporte a ASLR.

Use **/allowbind: no** para impedir que Bind.exe a DLL de associação.

Para obter mais informações, consulte o [/ALLOWBIND](../../build/reference/allowbind-prevent-dll-binding.md) a opção de vinculador.

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](../../build/reference/editbin-options.md)