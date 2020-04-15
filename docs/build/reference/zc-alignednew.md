---
title: /Zc:alignedNew (alocação com excesso de alinhamento C++17)
ms.date: 05/18/2019
f1_keywords:
- /Zc:alignedNew
helpviewer_keywords:
- /Zc:alignedNew
- Zc:alignedNew
- -Zc:alignedNew
ms.openlocfilehash: 041f62bbbf5f7a2750960d21d1534cf6daf4b874
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81335695"
---
# <a name="zcalignednew-c17-over-aligned-allocation"></a>/Zc:alignedNew (alocação com excesso de alinhamento C++17)

Habilite o suporte para alocação de memória dinâmica do operador **new** com excesso de alinhamento do C++17 alinhada em limites maiores que o padrão para o tipo alinhado padrão de tamanho máximo, **max\_align\_t**.

## <a name="syntax"></a>Sintaxe

> **/Zc:alinhadoNovo**\[-]

## <a name="remarks"></a>Comentários

O compilador MSVC e a biblioteca são compatíveis com alocação de memória dinâmica padrão com excesso de alinhamento C++17. Quando a opção **/Zc:alignedNew** é especificada, `new Example;` uma alocação dinâmica, como respeita `max_align_t`o alinhamento do *Exemplo,* mesmo quando é maior do que , o maior alinhamento necessário para qualquer tipo fundamental. Quando o alinhamento do tipo alocado não é mais do que o alinhamento garantido pelo operador original **novo,** disponível `new Example;` como o `::operator new(size_t)` valor da macro ** \_ \_predefinida STDCPP\_\_DEFAULT NEW\_ALIGNMENT,\_** a declaração resulta em uma chamada como fez em C++14. Quando o alinhamento é maior do que `::operator new(size_t, align_val_t)` ** \_ \_o PADRÃO STDCPP\_\_NOVO\_ALINHAMENTO,\_** a implementação obtém a memória usando . Da mesma forma, a exclusão de tipos com excesso de alinhamento invoca `::operator delete(void*, align_val_t)` ou a assinatura de exclusão dimensionada `::operator delete(void*, size_t, align_val_t)`.

A opção **/Zc:alignedNew** estará disponível somente quando [/std:c++17](std-specify-language-standard-version.md) ou [/std:c++latest](std-specify-language-standard-version.md) estiver habilitado. Em **/std:c++17** ou **/std:c++latest**, **/Zc:alignedNew** é habilitado por padrão para conformidade com o padrão ISO do C++17. Se o único motivo de implementar os operadores **new** e **delete** for dar suporte a alocações com excesso de alinhamento, você poderá não precisar mais desse código no modo do C++17. Para desligar essa opção e reverter para o comportamento de **new** e **delete** do C++14 ao usar **/std::c++17** ou **/std:c++latest**, especifique **/Zc:alignedNew-**. Se você implementar os operadores **new** e **delete**, mas não estiver pronto para implementar as sobrecargas dos operadores **new** e **delete** com excesso de alinhamento e que têm o parâmetro `align_val_t`, use a opção **/Zc:alignedNew-** para impedir que o compilador e a Biblioteca Padrão gerem chamadas para as sobrecargas com alinhamento excessivo. A opção [/permissive-](permissive-standards-conformance.md) não altera a configuração padrão de **/Zc:alignedNew**.

O suporte para **/Zc:alignedNew** está disponível desde o Visual Studio 2017 versão 15.5.

## <a name="example"></a>Exemplo

Nesta amostra, é possível ver como os operadores **new** e **delete** se comportam quando a opção **/Zc:alignedNew** está definida.

```cpp
// alignedNew.cpp
// Compile by using: cl /EHsc /std:c++17 /W4 alignedNew.cpp
#include <iostream>
#include <malloc.h>
#include <new>

// "old" unaligned overloads
void* operator new(std::size_t size) {
    auto ptr = malloc(size);
    std::cout << "unaligned new(" << size << ") = " << ptr << '\n';
    return ptr ? ptr : throw std::bad_alloc{};
}

void operator delete(void* ptr, std::size_t size) {
    std::cout << "unaligned sized delete(" << ptr << ", " << size << ")\n";
    free(ptr);
}

void operator delete(void* ptr) {
    std::cout << "unaligned unsized delete(" << ptr << ")\n";
    free(ptr);
}

// "new" over-aligned overloads
void* operator new(std::size_t size, std::align_val_t align) {
    auto ptr = _aligned_malloc(size, static_cast<std::size_t>(align));
    std::cout << "aligned new(" << size << ", " <<
        static_cast<std::size_t>(align) << ") = " << ptr << '\n';
    return ptr ? ptr : throw std::bad_alloc{};
}

void operator delete(void* ptr, std::size_t size, std::align_val_t align) {
    std::cout << "aligned sized delete(" << ptr << ", " << size <<
        ", " << static_cast<std::size_t>(align) << ")\n";
    _aligned_free(ptr);
}

void operator delete(void* ptr, std::align_val_t align) {
    std::cout << "aligned unsized delete(" << ptr <<
        ", " << static_cast<std::size_t>(align) << ")\n";
    _aligned_free(ptr);
}

struct alignas(256) OverAligned {}; // warning C4324, structure is padded

int main() {
    delete new int;
    delete new OverAligned;
}
```

Esta saída é comum para builds de 32 bits. Os valores do ponteiro variam de acordo com o local no qual seu aplicativo é executado na memória.

```Output
unaligned new(4) = 009FD0D0
unaligned sized delete(009FD0D0, 4)
aligned new(256, 256) = 009FE800
aligned sized delete(009FE800, 256, 256)
```

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [Comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de**propriedade** **Configuração Propriedades** > **C/C++.** > 

1. Modifique a propriedade **Opções Adicionais** para incluir **/Zc:alignedNew** ou **/Zc:alignedNew-** e escolha **OK**.

## <a name="see-also"></a>Confira também

[/Zc (conformidade)](zc-conformance.md)
