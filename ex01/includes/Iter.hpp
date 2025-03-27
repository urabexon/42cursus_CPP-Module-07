/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirokiurabe <hirokiurabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:59:38 by urabex            #+#    #+#             */
/*   Updated: 2025/03/27 17:38:44 by hirokiurabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void    iter(T *array, size_t length, void (*f)(T&)) {
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

// constでも対応させるようにする
template <typename T>
void    iter(const T *array, size_t length, void (*f)(const T&)) {
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

/*
    flushは出力バッファを強制的に今すぐ画面に出力させる関数
    std::cout はパフォーマンスのために、すぐには画面に出力しないことがある。
    代わりにバッファ、一時的な領域にデータを貯めておいて、\n文字やバッファが満杯になるなどのタイミングで
    まとめて出力する性質がある。
    それを無視して即出力する
*/
template <typename T>
void    out(T& out) {
    std::cout << out << " " <<std::flush;
}

#endif
