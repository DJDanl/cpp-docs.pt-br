---
title: Classe Platform::DisconnectedException
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::DisconnectedException
- VCCORLIB/Platform::DisconnectedException::DisconnectedException
helpviewer_keywords:
- Platform::DisconnectedException
ms.assetid: c25e0d64-5bff-4c21-88e5-c4ec2776fa7f
ms.openlocfilehash: 56276a7d09cc82e05886c2c67a4784993083adb5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62387611"
---
# <a name="platformdisconnectedexception-class"></a>Classe Platform::DisconnectedException

Gerada quando um objeto de proxy COM tenta referenciar um servidor COM que não existe

## <a name="syntax"></a>Sintaxe

```
public ref class DisconnectedException : COMException,    IException,    IPrintable,    IEquatable
```

### <a name="remarks"></a>Comentários

Quando a classe A referencia outra classe (classe B), que está em um processo separado, a classe A exige um objeto de proxy para se comunicar com o servidor COM fora do processo que contém a classe B. Às vezes, o servidor pode ficar sem memória sem o reconhecimento da classe A. Neste caso, a exceção RPC_E_DISCONNECTED é gerada e é traduzida como Platform::DisconnectedException. Um cenário no qual isso pode ocorrer é quando uma fonte de evento invoca um representante que lhe foi passado, porém o representante foi destruído em algum momento após ser inscrito no evento. Quando isso ocorre, a fonte do evento remove o representante da sua lista de invocação.

Para obter mais informações, consulte a classe [COMException](../cppcx/platform-comexception-class.md) .

### <a name="requirements"></a>Requisitos

**Cliente com suporte mínimo:** Windows 8

**Servidor com suporte mínimo:** Windows Server 2012

**Namespace:** Plataforma

**Metadados:** platform.winmd

## <a name="see-also"></a>Consulte também

[Classe Platform::COMException](../cppcx/platform-comexception-class.md)
