---
title: Estrutura SOCKADDR_IN
ms.date: 11/04/2016
f1_keywords:
- SOCKADDR_IN
helpviewer_keywords:
- SOCKADDR_IN structure [MFC]
ms.assetid: e8cd7c34-78bd-4e28-a990-eb3ca070b7a6
ms.openlocfilehash: 22d02b2e3c6fd7151e59cad0f3233539c04a16e0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50431220"
---
# <a name="sockaddrin-structure"></a>Estrutura SOCKADDR_IN

Na família de endereços da Internet, o `SOCKADDR_IN` estrutura é usada pelos soquetes do Windows para especificar um endereço de ponto de extremidade local ou remoto ao qual se conectar a um soquete.

## <a name="syntax"></a>Sintaxe

```
struct sockaddr_in{
    short sin_family;
    unsigned short sin_port;
struct in_addr sin_addr;
    char sin_zero[8];
};
```

#### <a name="parameters"></a>Parâmetros

*sin_family*<br/>
Família de endereços (deve ser AF_INET).

*sin_port*<br/>
Porta do IP.

*sin_addr*<br/>
Endereço IP.

*sin_zero*<br/>
Preenchimento para fazer o mesmo tamanho que a estrutura `SOCKADDR`.

## <a name="remarks"></a>Comentários

Essa é a forma do `SOCKADDR` estruturar específicas para a família de endereços de Internet e pode ser convertido em `SOCKADDR`.

O componente de endereço IP dessa estrutura é do tipo `IN_ADDR`. O `IN_ADDR` estrutura é definida no arquivo de cabeçalho WINSOCK do Windows Sockets. H da seguinte maneira:

```
struct in_addr {
    union {
        struct {
            unsigned char s_b1, s_b2, s_b3, s_b4;
        } S_un_b;
        struct {
            unsigned short s_w1, s_w2;
        } S_un_w;
        unsigned long S_addr;
    } S_un;
};
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** winsock2.h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[Estrutura SOCKADDR](../../mfc/reference/sockaddr-structure.md)
