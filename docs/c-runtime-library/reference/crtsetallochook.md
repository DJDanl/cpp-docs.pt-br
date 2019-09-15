---
title: _CrtSetAllocHook
ms.date: 11/04/2016
api_name:
- _CrtSetAllocHook
api_location:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _CrtSetAllocHook
- CrtSetAllocHook
helpviewer_keywords:
- _CrtSetAllocHook function
- CrtSetAllocHook function
ms.assetid: 405df37b-2fd1-42c8-83bc-90887f17f29d
ms.openlocfilehash: 303f682b54abc5e44cb7fdd4c89012dd9913288b
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70938493"
---
# <a name="_crtsetallochook"></a>_CrtSetAllocHook

Instala uma função de alocação definida pelo cliente vinculando-a ao processo de alocação de memória de depuração em tempo de execução C (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
_CRT_ALLOC_HOOK _CrtSetAllocHook(
   _CRT_ALLOC_HOOK allocHook
);
```

### <a name="parameters"></a>Parâmetros

*allocHook*<br/>
Nova função de alocação definida pelo cliente a ser vinculada ao processo de alocação de memória de depuração em tempo de execução C.

## <a name="return-value"></a>Valor de retorno

Retorna a função de gancho de alocação definida anteriormente ou **NULL** se *allocHook* for **nulo**.

## <a name="remarks"></a>Comentários

O **_CrtSetAllocHook** permite que um aplicativo vincule sua própria função de alocação ao processo de alocação de memória da biblioteca de depuração em tempo de execução do C. Como resultado, todas as chamadas a uma função de alocação de depuração para alocar, realocar ou liberar um bloco de memória disparam uma chamada à função de gancho do aplicativo. O **_CrtSetAllocHook** fornece um aplicativo com um método fácil para testar como o aplicativo lida com situações de memória insuficiente, a capacidade de examinar os padrões de alocação e a oportunidade de registrar em log as informações de alocação para análise posterior. Quando [_DEBUG](../../c-runtime-library/debug.md) não é definido, as chamadas para **_CrtSetAllocHook** são removidas durante o pré-processamento.

A função **_CrtSetAllocHook** instala a nova função de alocação definida pelo cliente especificada em *allocHook* e retorna a função de gancho definida anteriormente. O seguinte exemplo demonstra como um gancho de alocação definido pelo cliente deve ser prototipado:

```C
int YourAllocHook( int allocType, void *userData, size_t size,
                   int blockType, long requestNumber,
                   const unsigned char *filename, int lineNumber);
```

O argumento **allocType** especifica o tipo de operação de alocação ( **_HOOK_ALLOC**, **_HOOK_REALLOC**e **_HOOK_FREE**) que disparou a chamada para a função de gancho da alocação. Quando o tipo de alocação de disparo é **_HOOK_FREE**, *UserData* é um ponteiro para a seção de dados do usuário do bloco de memória prestes a ser liberado. No entanto, quando o tipo de alocação de disparo é **_HOOK_ALLOC** ou **_HOOK_REALLOC**, *UserData* é **nulo** porque o bloco de memória ainda não foi alocado.

*tamanho* especifica o tamanho do bloco de memória em bytes, *blockType* indica o tipo de bloco de memória, *requestNumber* é o número de ordem de alocação de objeto do bloco de memória e, se disponível, *filename* e **LineNumber** especifique o nome do arquivo de origem e o número da linha em que a operação de alocação de disparo foi iniciada.

Depois que a função de gancho concluir o processamento, ela deve retornar um valor booliano, que explica ao processo principal de alocação em tempo de execução C como continuar. Quando a função Hook quer que o processo de alocação principal continue como se a função Hook nunca tivesse sido chamada, a função Hook deve retornar **true**. Isso faz com que a operação de alocação de gatilho original seja executada. Ao usar essa implementação, a função de gancho pode coletar e salvar as informações de alocação para análise posterior, sem interferir na operação de alocação atual ou no estado do heap de depuração.

Quando a função de gancho quer que o processo de alocação principal continue como se a operação de disparo de alocação fosse chamada e falhou, a função de gancho deve retornar **false**. Ao usar essa implementação, a função de gancho pode simular uma ampla variedade de condições de memória e estados de heap de depuração para testar como o aplicativo manipula cada situação.

Para limpar a função de gancho, passe **NULL** para **_CrtSetAllocHook**.

Para obter mais informações sobre como o **_CrtSetAllocHook** pode ser usado com outras funções de gerenciamento de memória ou como escrever suas próprias funções de gancho definidas pelo cliente, consulte [depurar função do gancho](/visualstudio/debugger/debug-hook-function-writing).

> [!NOTE]
> Não há suporte para **_CrtSetAllocHook** em **/CLR: Pure**. As opções de compilador **/CLR: Pure** e **/CLR: safe** são preteridas no Visual Studio 2015 e removidas no Visual Studio 2017.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_CrtSetAllocHook**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

Para obter um exemplo de como usar o **_CrtSetAllocHook**, consulte [crt_dbg2](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/crt/crt_dbg2).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[_CrtGetAllocHook](crtgetallochook.md)<br/>
