---
title: _heapwalk
ms.date: 11/04/2016
api_name:
- _heapwalk
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
- api-ms-win-crt-heap-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- heapwalk
- _heapwalk
helpviewer_keywords:
- debugging [CRT], heap-related problems
- heapwalk function
- _heapwalk function
ms.assetid: 2df67649-fb00-4570-a8b1-a4eca5738744
ms.openlocfilehash: 8dc7ee9335f227bde93a414748ff70b165c44f8d
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70954771"
---
# <a name="_heapwalk"></a>_heapwalk

Percorre o heap e retorna informações sobre a próxima entrada.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime, exceto em builds de depuração. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _heapwalk( _HEAPINFO *entryinfo );
```

### <a name="parameters"></a>Parâmetros

*entryinfo*<br/>
Buffer que conterá informações do heap.

## <a name="return-value"></a>Valor de retorno

**_heapwalk** retorna uma das seguintes constantes de manifesto de inteiro definidas em malloc. h.

|Valor retornado|Significado|
|-|-|
|**_HEAPBADBEGIN**| As informações do cabeçalho inicial são inválidas ou não foram encontradas.|
|**_HEAPBADNODE**| Heap danificado ou nó inválido encontrado.|
|**_HEAPBADPTR**| O campo **_pentry** da estrutura **_HEAPINFO** não contém um ponteiro válido no heap ou *entryinfo* é um ponteiro nulo.|
|**_HEAPEND**| Fim do heap alcançado com êxito.|
|**_HEAPEMPTY**| Heap não inicializado.|
|**_HEAPOK**| Não há erros até agora; *entryinfo* é atualizado com informações sobre a próxima entrada de heap.|

Além disso, se ocorrer um erro, **_heapwalk** definirá **errno** como **ENOSYS**.

## <a name="remarks"></a>Comentários

A função **_heapwalk** ajuda a depurar problemas relacionados a heap em programas. A função percorre o heap, atravessando uma entrada por chamada e retorna um ponteiro para uma estrutura do tipo **_HEAPINFO** que contém informações sobre a próxima entrada de heap. O tipo **_HEAPINFO** , definido em malloc. h, contém os elementos a seguir.

|Campo|Significado|
|-|-|
|`int *_pentry`|Ponto de entrada do heap.|
|`size_t _size`|Tamanho da entrada do heap.|
|`int _useflag`|Sinalizador que indica se a entrada do heap está sendo utilizada.|

Uma chamada para **_heapwalk** que retorna **_HEAPOK** armazena o tamanho da entrada no campo **_size** e define o campo **_useflag** como **_FREEENTRY** ou **_USEDENTRY** (ambos são constantes definidas em malloc. h). Para obter essas informações sobre a primeira entrada no heap, passe **_heapwalk** um ponteiro para uma estrutura **_HEAPINFO** cujo membro **_pentry** é **nulo**. Se o sistema operacional não oferecer suporte a **_heapwalk**(por exemplo, Windows 98), a função retornará **_HEAPEND** e definirá **errno** como **ENOSYS**.

Esta função valida seu parâmetro. Se *entryinfo* for um ponteiro NULL, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** será definido como **EINVAL** e a função retornará **_HEAPBADPTR**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_heapwalk**|\<malloc.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_heapwalk.c

// This program "walks" the heap, starting
// at the beginning (_pentry = NULL). It prints out each
// heap entry's use, location, and size. It also prints
// out information about the overall state of the heap as
// soon as _heapwalk returns a value other than _HEAPOK
// or if the loop has iterated 100 times.

#include <stdio.h>
#include <malloc.h>

void heapdump(void);

int main(void)
{
    char *buffer;

    heapdump();
    if((buffer = (char *)malloc(59)) != NULL)
    {
        heapdump();
        free(buffer);
    }
    heapdump();
}

void heapdump(void)
{
    _HEAPINFO hinfo;
    int heapstatus;
    int numLoops;
    hinfo._pentry = NULL;
    numLoops = 0;
    while((heapstatus = _heapwalk(&hinfo)) == _HEAPOK &&
          numLoops < 100)
    {
        printf("%8s block at %Fp of size %4.4X\n",
               (hinfo._useflag == _USEDENTRY ? "USED" : "FREE"),
               hinfo._pentry, hinfo._size);
        numLoops++;
    }

    switch(heapstatus)
    {
    case _HEAPEMPTY:
        printf("OK - empty heap\n");
        break;
    case _HEAPEND:
        printf("OK - end of heap\n");
        break;
    case _HEAPBADPTR:
        printf("ERROR - bad pointer to heap\n");
        break;
    case _HEAPBADBEGIN:
        printf("ERROR - bad start of heap\n");
        break;
    case _HEAPBADNODE:
        printf("ERROR - bad node in heap\n");
        break;
    }
}
```

```Output
    USED block at 00310650 of size 0100
    USED block at 00310758 of size 0800
    USED block at 00310F60 of size 0080
    FREE block at 00310FF0 of size 0398
    USED block at 00311390 of size 000D
    USED block at 003113A8 of size 00B4
    USED block at 00311468 of size 0034
    USED block at 003114A8 of size 0039
...
    USED block at 00312228 of size 0010
    USED block at 00312240 of size 1000
    FREE block at 00313250 of size 1DB0
OK - end of heap
```

## <a name="see-also"></a>Consulte também

[Alocação de Memória](../../c-runtime-library/memory-allocation.md)<br/>
[_heapadd](../../c-runtime-library/heapadd.md)<br/>
[_heapchk](heapchk.md)<br/>
[_heapmin](heapmin.md)<br/>
[_heapset](../../c-runtime-library/heapset.md)<br/>
