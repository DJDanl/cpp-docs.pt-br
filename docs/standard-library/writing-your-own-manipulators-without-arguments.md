---
title: Elaborando os seus próprios manipuladores sem argumentos
ms.date: 11/04/2016
helpviewer_keywords:
- manipulators
ms.assetid: 2dc62d09-45b7-454d-bd9d-55f3c72c206d
ms.openlocfilehash: 0c3037c007e9388485f9553f9d2b0a69a1980b9a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62410818"
---
# <a name="writing-your-own-manipulators-without-arguments"></a>Elaborando os seus próprios manipuladores sem argumentos

Escrever manipuladores que não usam argumentos não requer a derivação das classes nem o uso de macros complexas. Suponha que sua impressora requer o par \<ESC>[ para entrar no modo negrito. Você pode inserir este par diretamente no fluxo:

```cpp
cout << "regular " << '\033' << '[' << "boldface" << endl;
```

Ou você pode definir o manipulador `bold`, que insere os caracteres:

```cpp
ostream& bold(ostream& os) {
    return os << '\033' << '[';
}
cout << "regular " << bold << "boldface" << endl;
```

A função definida globalmente `bold` usa um argumento de referência `ostream` e retorna a referência `ostream`. Não é uma função membro nem um amigo, pois não precisa ter acesso a nenhum elemento de classe privada. A função `bold` se conecta ao fluxo porque o operador `<<` do fluxo está sobrecarregado para aceitar esse tipo de função usando uma declaração semelhante a esta:

```cpp
_Myt& operator<<(ios_base& (__cdecl *_Pfn)(ios_base&))
{
    // call ios_base manipulator
    (*_Pfn)(*(ios_base *)this);

    return (*this);
}
```

Você pode usar esse recurso para estender outros operadores sobrecarregados. Nesse caso, é incidental que `bold` insira caracteres no fluxo. A função é chamada quando é inserida no fluxo e não necessariamente quando os caracteres adjacentes são impressos. Dessa forma, a impressão poderia ser atrasada por causa do buffer do fluxo.

## <a name="see-also"></a>Consulte também

[Fluxos de saída](../standard-library/output-streams.md)<br/>
