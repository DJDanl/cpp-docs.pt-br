---
title: __fastfail
ms.date: 11/04/2016
ms.assetid: 9cd32639-e395-4c75-9f3a-ac3ba7f49921
ms.openlocfilehash: e96d981be5c5186d6cc472cc8f4dffcbf1c2b7bf
ms.sourcegitcommit: bd637e9c39650cfd530520ea978a22fa4caa0e42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/07/2019
ms.locfileid: "55849470"
---
# <a name="fastfail"></a>__fastfail

**Seção específica da Microsoft**

Encerra imediatamente o processo de chamada com sobrecarga mínima.

## <a name="syntax"></a>Sintaxe

```
void __fastfail(unsigned int code);
```

#### <a name="parameters"></a>Parâmetros

*code*<br/>
[in] Um `FAST_FAIL_<description>` constante simbólica de Winnt. h ou WDM. h indica o motivo do término do processo.

## <a name="return-value"></a>Valor de retorno

O intrínseco `__fastfail` não retorna.

## <a name="remarks"></a>Comentários

O `__fastfail` intrínseco que fornece um mecanismo para um *rápida fail* solicitação — uma maneira para um processo potencialmente corrompido de terminação imediata do processo de solicitação. Falhas críticas que podem ter corrompido o estado de programa e pilha além da recuperação não podem ser tratadas pela recurso de manipulação de exceção regular. Use `__fastfail` para finalizar o processo usando uma sobrecarga mínima.

Internamente, `__fastfail` é implementado usando diversos mecanismos de arquitetura:

|Arquitetura|Instrução|Local do argumento de código|
|------------------|-----------------|-------------------------------|
|x86|int 0x29|ecx|
|X64|int 0x29|rcx|
|ARM|Opcode 0xDEFB|r0|
|ARM64|OpCode 0xF003|x0|

Uma solicitação de falha rápida é independente e normalmente exige apenas dois instruções para executar. Após a execução de uma solicitação de falha rápida, o kernel executa a ação apropriada. No código do modo de usuário, não há nenhuma dependência de memória além do ponteiro de instruções quando um evento de falha rápida é gerado. Isso aumenta sua confiabilidade, mesmo se houver corrupção de memória grave.

O argumento `code`, uma das constantes simbólicas `FAST_FAIL_<description>` de winnt.h or wdm.h, descreve o tipo de condição de falha e é incorporados em relatórios de falha de uma maneira específica ao ambiente.

Solicitações de falha rápida do modo de usuário são exibidas como uma segunda chance de exceção não continuada, com o código de exceção 0xC0000409 e pelo menos um parâmetro de exceção. O primeiro parâmetro de exceção é o valor `code`. Esse código de exceção indica ao WER (Relatório de Erros do Windows) e à infraestrutura de depuração que o processo está corrompido e que as ações mínimas no processo devem ser consideradas em resposta à falha. Solicitações de falha rápida do modo kernel são implementadas usando um código de verificação de bugs dedicado `KERNEL_SECURITY_CHECK_FAILURE` (0x139). Em ambos os casos, nenhum manipuladores de exceção é chamado porque o programa deve ser em um estado corrompido. Se um depurador estiver presente, terá a oportunidade de examinar o estado do programa antes do término.

Suporte para o mecanismo de falha rápida nativa iniciado no Windows 8. Sistemas operacionais Windows que não dão suporte a instrução de falha rápida nativamente tratarão normalmente uma solicitação falha rápida como uma violação de acesso ou como uma verificação de bugs `UNEXPECTED_KERNEL_MODE_TRAP`. Nesses casos, o programa é ainda encerrado, mas não necessariamente mais rápido.

`__fastfail` só está disponível como um intrínseco.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__fastfail`|x86, x64, ARM, ARM64|

**Arquivo de cabeçalho** \<intrin. h >

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
