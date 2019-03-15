---
title: '/ZC: alignednew (c + + 17 excessivamente alinhados alocação)'
ms.date: 02/28/2018
f1_keywords:
- /Zc:alignedNew
helpviewer_keywords:
- /Zc:alignedNew
- Zc:alignedNew
- -Zc:alignedNew
ms.openlocfilehash: e0d850d54611579288b81a334af4abdfab6e411c
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57820332"
---
# <a name="zcalignednew-c17-over-aligned-allocation"></a>/ZC: alignednew (c + + 17 excessivamente alinhados alocação)

Habilitar o suporte para o c++17 sobrealinhados **novos**, a alocação de memória dinâmica alinhada em limites de maiores que o padrão para o tamanho máximo padrão tipo alinhado, **max\_alinhar\_t**.

## <a name="syntax"></a>Sintaxe

> **/Zc:alignedNew**[-]

## <a name="remarks"></a>Comentários

Visual Studio versão 15.5 permite que o compilador e suporte de biblioteca para C + + 17 standard excessivamente alinhados alocação de memória dinâmica. Quando o **/ZC: alignednew** opção for especificada, uma alocação dinâmica, como `new Example;` respeita o alinhamento dos *exemplo* mesmo quando ele é maior do que `max_align_t`, maior alinhamento necessário para qualquer tipo fundamental. Quando o alinhamento do tipo alocado é não mais do que isso garantido pelo operador original **novos**, disponível como o valor da macro predefinida  **\_ \_STDCPP\_padrão \_NEW\_ALINHAMENTO\_\_**, a instrução `new Example;` resulta em uma chamada para `::operator new(size_t)` como fazia no C + + 14. Quando o alinhamento é maior que  **\_ \_STDCPP\_padrão\_NEW\_ALINHAMENTO\_\_**, em vez disso obtém a implementação a memória usando `::operator new(size_t, align_val_t)`. Da mesma forma, a exclusão de tipos excessivamente alinhados invoca `::operator delete(void*, align_val_t)` ou o tamanho excluir assinatura `::operator delete(void*, size_t, align_val_t)`.

O **/ZC: alignednew** opção está disponível somente quando [/std:c++17 + + 17](std-specify-language-standard-version.md) ou [/std:c++17 + + mais recente](std-specify-language-standard-version.md) está habilitado. Sob **/std:c++17 + + 17** ou **/std: c + + mais recente**, **/ZC: alignednew** é habilitado por padrão em conformidade com ISO C++ 17 standard. Se a única razão, você implementa o operador **novos** e **excluir** deve dar suporte a alocações excessivamente alinhadas, você pode não precisar mais esse código no modo c++17. Para desativar essa opção e reverter para o comportamento do c++14 dos **novos** e **excluir** quando **/std::c + + 17** ou **/std:c++17 + + mais recente** for especificado, especificar **/Zc:alignedNew-**. Se você implementar o operador **novos** e **excluir** , mas você não estiver pronto para implementar o operador excessivamente alinhado **nova** e **excluir** sobrecargas que têm o `align_val_t` parâmetro, use o **/Zc:alignedNew-** opção para impedir que o compilador e a biblioteca padrão de chamadas para as sobrecargas excessivamente alinhadas. O [/permissive--](permissive-standards-conformance.md) opção não altera a configuração padrão de **/ZC: alignednew**.

## <a name="example"></a>Exemplo

Este exemplo mostra como operador **novos** e o operador **excluir** se comportam quando o **/ZC: alignednew** opção está definida.

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

Esta saída é típica para compilações de 32 bits. O ponteiro valores variam de acordo com base em onde seu aplicativo é executado na memória.

```Output
unaligned new(4) = 009FD0D0
unaligned sized delete(009FD0D0, 4)
aligned new(256, 256) = 009FE800
aligned sized delete(009FE800, 256, 256)
```

Para obter informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Modificar a **opções adicionais** propriedade incluir **/ZC: alignednew** ou **/Zc:alignedNew-** e, em seguida, escolha **Okey**.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](zc-conformance.md)
