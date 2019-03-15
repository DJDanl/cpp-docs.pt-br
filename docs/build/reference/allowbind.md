---
title: /ALLOWBIND
ms.date: 11/04/2016
f1_keywords:
- /allowbind
helpviewer_keywords:
- ALLOWBIND editbin option
- /ALLOWBIND editbin option
- -ALLOWBIND editbin option
ms.assetid: eaadbb8c-4339-4281-9a75-3a1ce2352ff8
ms.openlocfilehash: 4cb7e5a3627d865e2f2193dee096c72cced75f5f
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57819812"
---
# <a name="allowbind"></a>/ALLOWBIND

Especifica se uma DLL pode ser associada.

```

/ALLOWBIND[:NO]
```

## <a name="remarks"></a>Comentários

O **/ALLOWBIND** opção define um bit no cabeçalho de uma DLL que indica a Bind.exe que a imagem tem permissão para ser associado. Associação pode permitir que uma imagem a ser carregado mais rapidamente quando o carregador não precisa trocar base e realizar o ajuste de endereço para cada DLL referenciada. Talvez você não queira uma DLL seja vinculada caso ela tenha sido assinada digitalmente — associação invalida a assinatura. Associação não tem nenhum efeito se randomização de layout de espaço de endereço (ASLR) estiver habilitada para a imagem por meio **/DYNAMICBASE** em versões do Windows que dão suporte a ASLR.

Use **/allowbind: no** para impedir que Bind.exe a DLL de associação.

Para obter mais informações, consulte o [/ALLOWBIND](allowbind-prevent-dll-binding.md) a opção de vinculador.

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](editbin-options.md)
