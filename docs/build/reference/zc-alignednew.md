---
title: /Zc:alignedNew (alocação com excesso de alinhamento C++17)
ms.date: 05/18/2019
f1_keywords:
- /Zc:alignedNew
helpviewer_keywords:
- /Zc:alignedNew
- Zc:alignedNew
- -Zc:alignedNew
ms.openlocfilehash: f036c2d7bc4619685d2763702f447476e8e1a1e4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217188"
---
# <a name="zcalignednew-c17-over-aligned-allocation"></a>/Zc:alignedNew (alocação com excesso de alinhamento C++17)

Habilite o suporte para C++ 17 **`new`** , alocação de memória dinâmica alinhada em limites acima do padrão para o tipo alinhado padrão de tamanho máximo, **máximo de \_ alinhamento \_ t**.

## <a name="syntax"></a>Sintaxe

> **/Zc: alignedNew** \[ -]

## <a name="remarks"></a>Comentários

O compilador MSVC e a biblioteca são compatíveis com alocação de memória dinâmica padrão com excesso de alinhamento C++17. Quando a opção **/Zc: alignedNew** é especificada, uma alocação dinâmica, como `new Example;` respeita o alinhamento do *exemplo* , mesmo quando é maior que `max_align_t` , o maior alinhamento necessário para qualquer tipo fundamental. Quando o alinhamento do tipo alocado é não mais do que o alinhamento garantido pelo operador original **`new`** , disponível como o valor da macro predefinida ** \_ \_ STDCPP \_ \_ novo \_ \_ \_ alinhamento padrão**, a instrução `new Example;` resulta em uma chamada para `::operator new(size_t)` como fazia no c++ 14. Quando o alinhamento é maior que o ** \_ \_ \_ \_ novo \_ alinhamento \_ \_ padrão STDCPP**, a implementação, em vez disso, obtém a memória usando `::operator new(size_t, align_val_t)` . Da mesma forma, a exclusão de tipos com excesso de alinhamento invoca `::operator delete(void*, align_val_t)` ou a assinatura de exclusão dimensionada `::operator delete(void*, size_t, align_val_t)`.

A opção **/Zc:alignedNew** estará disponível somente quando [/std:c++17](std-specify-language-standard-version.md) ou [/std:c++latest](std-specify-language-standard-version.md) estiver habilitado. Em **/std:c++17** ou **/std:c++latest**, **/Zc:alignedNew** é habilitado por padrão para conformidade com o padrão ISO do C++17. Se o único motivo para implementar o operador **`new`** e **`delete`** for oferecer suporte a alocações sobrealinhadas, talvez você não precise mais desse código no modo c++ 17. Para desativar essa opção e reverter para o comportamento do C++ 14 de **`new`** e **`delete`** quando você usar **/std:: c++ 17** ou **/std: C + + Latest**, especifique **/Zc: alignedNew-**. Se você implementar **`new`** o operador e **`delete`** , mas não estiver pronto para implementar o operador superalinhado **`new`** e **`delete`** sobrecargas que têm o `align_val_t` parâmetro, use a opção **/Zc: alignedNew-** para impedir que o compilador e a biblioteca padrão gerem chamadas para sobrecargas sobrealinhadas. A opção [/permissive-](permissive-standards-conformance.md) não altera a configuração padrão de **/Zc:alignedNew**.

O suporte para **/Zc:alignedNew** está disponível desde o Visual Studio 2017 versão 15.5.

## <a name="example"></a>Exemplo

Este exemplo mostra como **`new`** o operador e **`delete`** o comportamento se comportam quando a opção **/Zc: alignedNew** é definida.

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

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Modifique a propriedade **Opções Adicionais** para incluir **/Zc:alignedNew** ou **/Zc:alignedNew-** e escolha **OK**.

## <a name="see-also"></a>Confira também

[/Zc (conformidade)](zc-conformance.md)
