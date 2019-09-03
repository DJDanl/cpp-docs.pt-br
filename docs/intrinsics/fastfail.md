---
title: __fastfail
ms.date: 09/02/2019
ms.assetid: 9cd32639-e395-4c75-9f3a-ac3ba7f49921
ms.openlocfilehash: 34198409c6a57eb494bfe819b367b71405a84e64
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70222191"
---
# <a name="__fastfail"></a>__fastfail

**Seção específica da Microsoft**

Encerra imediatamente o processo de chamada com sobrecarga mínima.

## <a name="syntax"></a>Sintaxe

```C
void __fastfail(unsigned int code);
```

### <a name="parameters"></a>Parâmetros

*auto-completar*\
no Uma `FAST_FAIL_<description>` constante simbólica de Winnt. h ou WDM. h que indica o motivo da finalização do processo.

## <a name="return-value"></a>Valor retornado

O intrínseco `__fastfail` não retorna.

## <a name="remarks"></a>Comentários

O `__fastfail` intrínseco fornece um mecanismo para uma solicitação de *falha rápida* – uma maneira de um processo potencialmente corrompido solicitar o encerramento imediato do processo. Falhas críticas que podem ter corrompido o estado de programa e pilha além da recuperação não podem ser tratadas pela recurso de manipulação de exceção regular. Use `__fastfail` para finalizar o processo usando uma sobrecarga mínima.

Internamente, `__fastfail` é implementado usando diversos mecanismos de arquitetura:

|Arquitetura|Instrução|Local do argumento de código|
|------------------|-----------------|-------------------------------|
|x86|int 0x29|`ecx`|
|X64|int 0x29|`rcx`|
|ARM|Opcode 0xDEFB|`r0`|
|ARM64|Opcode 0xF003|`x0`|

Uma solicitação de falha rápida é independente e normalmente exige apenas dois instruções para executar. Depois que uma solicitação de falha rápida for executada, o kernel executará a ação apropriada. No código do modo de usuário, não há nenhuma dependência de memória além do ponteiro de instruções quando um evento de falha rápida é gerado. Isso maximiza sua confiabilidade, mesmo em casos de corrupção de memória grave.

O `code` argumento, uma `FAST_FAIL_<description>` das constantes simbólicas de Winnt. h ou WDM. h, descreve o tipo de condição de falha. Ele é incorporado aos relatórios de falha de maneira específica do ambiente.

As solicitações de falha rápida do modo de usuário aparecem como uma exceção não continuável de segunda chance com o código de exceção 0xC0000409 e com pelo menos um parâmetro de exceção. O primeiro parâmetro de exceção é o valor `code`. Esse código de exceção indica ao Relatório de Erros do Windows (WER) e à infraestrutura de depuração que o processo está corrompido e que ações mínimas em processo devem ser executadas em resposta à falha. Solicitações de falha rápida do modo kernel são implementadas usando um código de verificação de bugs dedicado `KERNEL_SECURITY_CHECK_FAILURE` (0x139). Em ambos os casos, nenhum manipuladores de exceção é chamado porque o programa deve ser em um estado corrompido. Se um depurador estiver presente, será dada a oportunidade de examinar o estado do programa antes do encerramento.

Suporte para o mecanismo de falha rápida nativa iniciado no Windows 8. Os sistemas operacionais Windows que não dão suporte à instrução de falha rápida normalmente tratarão uma solicitação de falha rápida como violação de acesso ou como `UNEXPECTED_KERNEL_MODE_TRAP` uma verificação de bugs. Nesses casos, o programa é ainda encerrado, mas não necessariamente mais rápido.

`__fastfail` só está disponível como um intrínseco.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__fastfail`|x86, x64, ARM, ARM64|

**Arquivo de cabeçalho** \<> intrin. h

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
